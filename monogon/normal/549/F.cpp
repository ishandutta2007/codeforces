#include <bits/stdc++.h>

// adapted from: https://github.com/Tessil/robin-map
/**
 * MIT License
 *
 * Copyright (c) 2017 Tessil
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#define TSL_RH_THROW_OR_TERMINATE(ex, msg) throw ex(msg)
#if defined(__GNUC__) || defined(__clang__)
#define TSL_RH_LIKELY(exp) (__builtin_expect(!!(exp), true))
#else
#define TSL_RH_LIKELY(exp) (exp)
#endif
namespace tsl {
	namespace rh {
		template <std::size_t GrowthFactor> class power_of_two_growth_policy {
		  public:
			explicit power_of_two_growth_policy(std::size_t &min_bucket_count_in_out) {
				if (min_bucket_count_in_out > max_bucket_count()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
				if (min_bucket_count_in_out > 0) {
					min_bucket_count_in_out = round_up_to_power_of_two(min_bucket_count_in_out);
					m_mask = min_bucket_count_in_out - 1;
				} else {
					m_mask = 0;
				}
			}
			std::size_t bucket_for_hash(std::size_t hash) const noexcept { return hash & m_mask; }
			std::size_t next_bucket_count() const {
				if ((m_mask + 1) > max_bucket_count() / GrowthFactor) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}

				return (m_mask + 1) * GrowthFactor;
			}
			std::size_t max_bucket_count() const {
				return (std::numeric_limits<std::size_t>::max() / 2) + 1;
			}
			void clear() noexcept { m_mask = 0; }

		  private:
			static std::size_t round_up_to_power_of_two(std::size_t value) {
				if (is_power_of_two(value)) {
					return value;
				}
				if (value == 0) {
					return 1;
				}
				--value;
				for (std::size_t i = 1; i < sizeof(std::size_t) * CHAR_BIT; i *= 2) {
					value |= value >> i;
				}
				return value + 1;
			}
			static constexpr bool is_power_of_two(std::size_t value) {
				return value != 0 && (value & (value - 1)) == 0;
			}

		  protected:
			static_assert(is_power_of_two(GrowthFactor) && GrowthFactor >= 2,
						  "GrowthFactor must be a power of two >= 2.");

			std::size_t m_mask;
		};
		template <class GrowthFactor = std::ratio<3, 2>> class mod_growth_policy {
		  public:
			explicit mod_growth_policy(std::size_t &min_bucket_count_in_out) {
				if (min_bucket_count_in_out > max_bucket_count()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}

				if (min_bucket_count_in_out > 0) {
					m_mod = min_bucket_count_in_out;
				} else {
					m_mod = 1;
				}
			}
			std::size_t bucket_for_hash(std::size_t hash) const noexcept { return hash % m_mod; }
			std::size_t next_bucket_count() const {
				if (m_mod == max_bucket_count()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
				const double next_bucket_count =
					std::ceil(double(m_mod) * REHASH_SIZE_MULTIPLICATION_FACTOR);
				if (!std::isnormal(next_bucket_count)) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
				if (next_bucket_count > double(max_bucket_count())) {
					return max_bucket_count();
				} else {
					return std::size_t(next_bucket_count);
				}
			}
			std::size_t max_bucket_count() const { return MAX_BUCKET_COUNT; }
			void clear() noexcept { m_mod = 1; }

		  private:
			static constexpr double REHASH_SIZE_MULTIPLICATION_FACTOR =
				1.0 * GrowthFactor::num / GrowthFactor::den;
			static const std::size_t MAX_BUCKET_COUNT = std::size_t(double(
				std::numeric_limits<std::size_t>::max() / REHASH_SIZE_MULTIPLICATION_FACTOR));
			static_assert(REHASH_SIZE_MULTIPLICATION_FACTOR >= 1.1,
						  "Growth factor should be >= 1.1.");
			std::size_t m_mod;
		};
		namespace detail {
			static constexpr const std::array<std::size_t, 40> PRIMES = {
				{1ul,		  5ul,			17ul,		  29ul,		   37ul,		53ul,
				 67ul,		  79ul,			97ul,		  131ul,	   193ul,		257ul,
				 389ul,		  521ul,		769ul,		  1031ul,	  1543ul,		2053ul,
				 3079ul,	  6151ul,		12289ul,	  24593ul,	 49157ul,		98317ul,
				 196613ul,	393241ul,		786433ul,	 1572869ul,   3145739ul,   6291469ul,
				 12582917ul,  25165843ul,   50331653ul,   100663319ul, 201326611ul, 402653189ul,
				 805306457ul, 1610612741ul, 3221225473ul, 4294967291ul}};
			template <unsigned int IPrime> static constexpr std::size_t mod(std::size_t hash) {
				return hash % PRIMES[IPrime];
			}
			static constexpr const std::array<std::size_t (*)(std::size_t), 40> MOD_PRIME = {
				{&mod<0>,  &mod<1>,  &mod<2>,  &mod<3>,  &mod<4>,  &mod<5>,  &mod<6>,  &mod<7>,
				 &mod<8>,  &mod<9>,  &mod<10>, &mod<11>, &mod<12>, &mod<13>, &mod<14>, &mod<15>,
				 &mod<16>, &mod<17>, &mod<18>, &mod<19>, &mod<20>, &mod<21>, &mod<22>, &mod<23>,
				 &mod<24>, &mod<25>, &mod<26>, &mod<27>, &mod<28>, &mod<29>, &mod<30>, &mod<31>,
				 &mod<32>, &mod<33>, &mod<34>, &mod<35>, &mod<36>, &mod<37>, &mod<38>, &mod<39>}};
		} // namespace detail
		class prime_growth_policy {
		  public:
			explicit prime_growth_policy(std::size_t &min_bucket_count_in_out) {
				auto it_prime = std::lower_bound(detail::PRIMES.begin(), detail::PRIMES.end(),
												 min_bucket_count_in_out);
				if (it_prime == detail::PRIMES.end()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}

				m_iprime =
					static_cast<unsigned int>(std::distance(detail::PRIMES.begin(), it_prime));
				if (min_bucket_count_in_out > 0) {
					min_bucket_count_in_out = *it_prime;
				} else {
					min_bucket_count_in_out = 0;
				}
			}

			std::size_t bucket_for_hash(std::size_t hash) const noexcept {
				return detail::MOD_PRIME[m_iprime](hash);
			}

			std::size_t next_bucket_count() const {
				if (m_iprime + 1 >= detail::PRIMES.size()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}

				return detail::PRIMES[m_iprime + 1];
			}

			std::size_t max_bucket_count() const { return detail::PRIMES.back(); }

			void clear() noexcept { m_iprime = 0; }

		  private:
			unsigned int m_iprime;

			static_assert(std::numeric_limits<decltype(m_iprime)>::max() >= detail::PRIMES.size(),
						  "The type of m_iprime is not big enough.");
		};

	} // namespace rh

	namespace detail_robin_hash {
		template <typename T> struct make_void { using type = void; };
		template <typename T, typename = void> struct has_is_transparent : std::false_type {};
		template <typename T>
		struct has_is_transparent<T, typename make_void<typename T::is_transparent>::type>
			: std::true_type {};
		template <typename U> struct is_power_of_two_policy : std::false_type {};
		template <std::size_t GrowthFactor>
		struct is_power_of_two_policy<tsl::rh::power_of_two_growth_policy<GrowthFactor>>
			: std::true_type {};
		template <class T> const T &clamp(const T &v, const T &lo, const T &hi) {
			return std::min(hi, std::max(lo, v));
		}
		template <typename T, typename U>
		static T numeric_cast(U value, const char *error_message = "numeric_cast() failed.") {
			T ret = static_cast<T>(value);
			if (static_cast<U>(ret) != value) {
				TSL_RH_THROW_OR_TERMINATE(std::runtime_error, error_message);
			}
			const bool is_same_signedness =
				(std::is_unsigned<T>::value && std::is_unsigned<U>::value) ||
				(std::is_signed<T>::value && std::is_signed<U>::value);
			if (!is_same_signedness && (ret < T{}) != (value < U{})) {
				TSL_RH_THROW_OR_TERMINATE(std::runtime_error, error_message);
			}

			return ret;
		}
		using truncated_hash_type = std::uint_least32_t;
		template <bool StoreHash> class bucket_entry_hash {
		  public:
			bool bucket_hash_equal(std::size_t /*hash*/) const noexcept { return true; }
			truncated_hash_type truncated_hash() const noexcept { return 0; }

		  protected:
			void set_hash(truncated_hash_type /*hash*/) noexcept {}
		};
		template <> class bucket_entry_hash<true> {
		  public:
			bool bucket_hash_equal(std::size_t hash) const noexcept {
				return m_hash == truncated_hash_type(hash);
			}
			truncated_hash_type truncated_hash() const noexcept { return m_hash; }

		  protected:
			void set_hash(truncated_hash_type hash) noexcept { m_hash = truncated_hash_type(hash); }

		  private:
			truncated_hash_type m_hash;
		};
		template <typename ValueType, bool StoreHash>
		class bucket_entry : public bucket_entry_hash<StoreHash> {
			using bucket_hash = bucket_entry_hash<StoreHash>;

		  public:
			using value_type = ValueType;
			using distance_type = std::int_least16_t;
			bucket_entry() noexcept
				: bucket_hash(), m_dist_from_ideal_bucket(EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET),
				  m_last_bucket(false) {}
			bucket_entry(bool last_bucket) noexcept
				: bucket_hash(), m_dist_from_ideal_bucket(EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET),
				  m_last_bucket(last_bucket) {}
			bucket_entry(const bucket_entry &other) noexcept(
				std::is_nothrow_copy_constructible<value_type>::value)
				: bucket_hash(other), m_dist_from_ideal_bucket(EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET),
				  m_last_bucket(other.m_last_bucket) {
				if (!other.empty()) {
					::new (static_cast<void *>(std::addressof(m_value))) value_type(other.value());
					m_dist_from_ideal_bucket = other.m_dist_from_ideal_bucket;
				}
			}
			bucket_entry(bucket_entry &&other) noexcept(
				std::is_nothrow_move_constructible<value_type>::value)
				: bucket_hash(std::move(other)),
				  m_dist_from_ideal_bucket(EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET),
				  m_last_bucket(other.m_last_bucket) {
				if (!other.empty()) {
					::new (static_cast<void *>(std::addressof(m_value)))
						value_type(std::move(other.value()));
					m_dist_from_ideal_bucket = other.m_dist_from_ideal_bucket;
				}
			}
			bucket_entry &operator=(const bucket_entry &other) noexcept(
				std::is_nothrow_copy_constructible<value_type>::value) {
				if (this != &other) {
					clear();
					bucket_hash::operator=(other);
					if (!other.empty()) {
						::new (static_cast<void *>(std::addressof(m_value)))
							value_type(other.value());
					}
					m_dist_from_ideal_bucket = other.m_dist_from_ideal_bucket;
					m_last_bucket = other.m_last_bucket;
				}
				return *this;
			}
			bucket_entry &operator=(bucket_entry &&) = delete;
			~bucket_entry() noexcept { clear(); }
			void clear() noexcept {
				if (!empty()) {
					destroy_value();
					m_dist_from_ideal_bucket = EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET;
				}
			}
			bool empty() const noexcept {
				return m_dist_from_ideal_bucket == EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET;
			}
			value_type &value() noexcept {
				return *reinterpret_cast<value_type *>(std::addressof(m_value));
			}
			const value_type &value() const noexcept {
				return *reinterpret_cast<const value_type *>(std::addressof(m_value));
			}
			distance_type dist_from_ideal_bucket() const noexcept {
				return m_dist_from_ideal_bucket;
			}
			bool last_bucket() const noexcept { return m_last_bucket; }
			void set_as_last_bucket() noexcept { m_last_bucket = true; }
			template <typename... Args>
			void set_value_of_empty_bucket(distance_type dist_from_ideal_bucket,
										   truncated_hash_type hash, Args &&... value_type_args) {
				::new (static_cast<void *>(std::addressof(m_value)))
					value_type(std::forward<Args>(value_type_args)...);
				this->set_hash(hash);
				m_dist_from_ideal_bucket = dist_from_ideal_bucket;
			}
			void swap_with_value_in_bucket(distance_type &dist_from_ideal_bucket,
										   truncated_hash_type &hash, value_type &value) {
				using std::swap;
				swap(value, this->value());
				swap(dist_from_ideal_bucket, m_dist_from_ideal_bucket);
				(void)hash;
				if (StoreHash) {
					const truncated_hash_type tmp_hash = this->truncated_hash();
					this->set_hash(hash);
					hash = tmp_hash;
				}
			}
			static truncated_hash_type truncate_hash(std::size_t hash) noexcept {
				return truncated_hash_type(hash);
			}

		  private:
			void destroy_value() noexcept { value().~value_type(); }

		  public:
			static const distance_type DIST_FROM_IDEAL_BUCKET_LIMIT = 4096;
			static_assert(DIST_FROM_IDEAL_BUCKET_LIMIT <=
							  std::numeric_limits<distance_type>::max() - 1,
						  "DIST_FROM_IDEAL_BUCKET_LIMIT must be <= "
						  "std::numeric_limits<distance_type>::max() - 1.");

		  private:
			using storage =
				typename std::aligned_storage<sizeof(value_type), alignof(value_type)>::type;
			static const distance_type EMPTY_MARKER_DIST_FROM_IDEAL_BUCKET = -1;
			distance_type m_dist_from_ideal_bucket;
			bool m_last_bucket;
			storage m_value;
		};
		template <class ValueType, class KeySelect, class ValueSelect, class Hash, class KeyEqual,
				  class Allocator, bool StoreHash, class GrowthPolicy>
		class robin_hash : private Hash, private KeyEqual, private GrowthPolicy {
		  private:
			template <typename U>
			using has_mapped_type =
				typename std::integral_constant<bool, !std::is_same<U, void>::value>;

			static_assert(noexcept(std::declval<GrowthPolicy>().bucket_for_hash(std::size_t(0))),
						  "GrowthPolicy::bucket_for_hash must be noexcept.");
			static_assert(noexcept(std::declval<GrowthPolicy>().clear()),
						  "GrowthPolicy::clear must be noexcept.");

		  public:
			template <bool IsConst> class robin_iterator;
			using key_type = typename KeySelect::key_type;
			using value_type = ValueType;
			using size_type = std::size_t;
			using difference_type = std::ptrdiff_t;
			using hasher = Hash;
			using key_equal = KeyEqual;
			using allocator_type = Allocator;
			using reference = value_type &;
			using const_reference = const value_type &;
			using pointer = value_type *;
			using const_pointer = const value_type *;
			using iterator = robin_iterator<false>;
			using const_iterator = robin_iterator<true>;

		  private:
			static constexpr bool STORE_HASH =
				StoreHash || ((sizeof(tsl::detail_robin_hash::bucket_entry<value_type, true>) ==
							   sizeof(tsl::detail_robin_hash::bucket_entry<value_type, false>)) &&
							  (sizeof(std::size_t) == sizeof(truncated_hash_type) ||
							   is_power_of_two_policy<GrowthPolicy>::value) &&
							  (!std::is_arithmetic<key_type>::value ||
							   !std::is_same<Hash, std::hash<key_type>>::value));
			static constexpr bool USE_STORED_HASH_ON_LOOKUP = StoreHash;
			static bool USE_STORED_HASH_ON_REHASH(size_type bucket_count) {
				(void)bucket_count;
				if (STORE_HASH && sizeof(std::size_t) == sizeof(truncated_hash_type)) {
					return true;
				} else if (STORE_HASH && is_power_of_two_policy<GrowthPolicy>::value) {
					return (bucket_count - 1) <= std::numeric_limits<truncated_hash_type>::max();
				} else {
					return false;
				}
			}
			using bucket_entry = tsl::detail_robin_hash::bucket_entry<value_type, STORE_HASH>;
			using distance_type = typename bucket_entry::distance_type;
			using buckets_allocator =
				typename std::allocator_traits<allocator_type>::template rebind_alloc<bucket_entry>;
			using buckets_container_type = std::vector<bucket_entry, buckets_allocator>;

		  public:
			template <bool IsConst> class robin_iterator {
				friend class robin_hash;

			  private:
				using bucket_entry_ptr =
					typename std::conditional<IsConst, const bucket_entry *, bucket_entry *>::type;
				robin_iterator(bucket_entry_ptr bucket) noexcept : m_bucket(bucket) {}

			  public:
				using iterator_category = std::forward_iterator_tag;
				using value_type = const typename robin_hash::value_type;
				using difference_type = std::ptrdiff_t;
				using reference = value_type &;
				using pointer = value_type *;
				robin_iterator() noexcept {}
				template <bool TIsConst = IsConst,
						  typename std::enable_if<TIsConst>::type * = nullptr>
				robin_iterator(const robin_iterator<!TIsConst> &other) noexcept
					: m_bucket(other.m_bucket) {}
				robin_iterator(const robin_iterator &other) = default;
				robin_iterator(robin_iterator &&other) = default;
				robin_iterator &operator=(const robin_iterator &other) = default;
				robin_iterator &operator=(robin_iterator &&other) = default;
				const typename robin_hash::key_type &key() const {
					return KeySelect()(m_bucket->value());
				}
				template <
					class U = ValueSelect,
					typename std::enable_if<has_mapped_type<U>::value && IsConst>::type * = nullptr>
				const typename U::value_type &value() const {
					return U()(m_bucket->value());
				}
				template <class U = ValueSelect,
						  typename std::enable_if<has_mapped_type<U>::value && !IsConst>::type * =
							  nullptr>
				typename U::value_type &value() {
					return U()(m_bucket->value());
				}
				reference operator*() const { return m_bucket->value(); }
				pointer operator->() const { return std::addressof(m_bucket->value()); }
				robin_iterator &operator++() {
					while (true) {
						if (m_bucket->last_bucket()) {
							++m_bucket;
							return *this;
						}
						++m_bucket;
						if (!m_bucket->empty()) {
							return *this;
						}
					}
				}
				robin_iterator operator++(int) {
					robin_iterator tmp(*this);
					++*this;

					return tmp;
				}
				friend bool operator==(const robin_iterator &lhs, const robin_iterator &rhs) {
					return lhs.m_bucket == rhs.m_bucket;
				}
				friend bool operator!=(const robin_iterator &lhs, const robin_iterator &rhs) {
					return !(lhs == rhs);
				}

			  private:
				bucket_entry_ptr m_bucket;
			};

		  public:
			robin_hash(size_type bucket_count, const Hash &hash, const KeyEqual &equal,
					   const Allocator &alloc, float min_load_factor = DEFAULT_MIN_LOAD_FACTOR,
					   float max_load_factor = DEFAULT_MAX_LOAD_FACTOR)
				: Hash(hash), KeyEqual(equal), GrowthPolicy(bucket_count),
				  m_buckets_data(
					  [&]() {
						  if (bucket_count > max_bucket_count()) {
							  TSL_RH_THROW_OR_TERMINATE(
								  std::length_error, "The map exceeds its maximum bucket count.");
						  }

						  return bucket_count;
					  }(),
					  alloc),
				  m_buckets(m_buckets_data.empty() ? static_empty_bucket_ptr()
												   : m_buckets_data.data()),
				  m_bucket_count(bucket_count), m_nb_elements(0), m_grow_on_next_insert(false),
				  m_try_skrink_on_next_insert(false) {
				if (m_bucket_count > 0) {
					m_buckets_data.back().set_as_last_bucket();
				}
				this->min_load_factor(min_load_factor);
				this->max_load_factor(max_load_factor);
			}

			robin_hash(const robin_hash &other)
				: Hash(other), KeyEqual(other), GrowthPolicy(other),
				  m_buckets_data(other.m_buckets_data),
				  m_buckets(m_buckets_data.empty() ? static_empty_bucket_ptr()
												   : m_buckets_data.data()),
				  m_bucket_count(other.m_bucket_count), m_nb_elements(other.m_nb_elements),
				  m_load_threshold(other.m_load_threshold),
				  m_max_load_factor(other.m_max_load_factor),
				  m_grow_on_next_insert(other.m_grow_on_next_insert),
				  m_min_load_factor(other.m_min_load_factor),
				  m_try_skrink_on_next_insert(other.m_try_skrink_on_next_insert) {}

			robin_hash(robin_hash &&other) noexcept(
				std::is_nothrow_move_constructible<Hash>::value
					&&std::is_nothrow_move_constructible<KeyEqual>::value
						&&std::is_nothrow_move_constructible<GrowthPolicy>::value
							&&std::is_nothrow_move_constructible<buckets_container_type>::value)
				: Hash(std::move(static_cast<Hash &>(other))),
				  KeyEqual(std::move(static_cast<KeyEqual &>(other))),
				  GrowthPolicy(std::move(static_cast<GrowthPolicy &>(other))),
				  m_buckets_data(std::move(other.m_buckets_data)),
				  m_buckets(m_buckets_data.empty() ? static_empty_bucket_ptr()
												   : m_buckets_data.data()),
				  m_bucket_count(other.m_bucket_count), m_nb_elements(other.m_nb_elements),
				  m_load_threshold(other.m_load_threshold),
				  m_max_load_factor(other.m_max_load_factor),
				  m_grow_on_next_insert(other.m_grow_on_next_insert),
				  m_min_load_factor(other.m_min_load_factor),
				  m_try_skrink_on_next_insert(other.m_try_skrink_on_next_insert) {
				other.GrowthPolicy::clear();
				other.m_buckets_data.clear();
				other.m_buckets = static_empty_bucket_ptr();
				other.m_bucket_count = 0;
				other.m_nb_elements = 0;
				other.m_load_threshold = 0;
				other.m_grow_on_next_insert = false;
				other.m_try_skrink_on_next_insert = false;
			}
			robin_hash &operator=(const robin_hash &other) {
				if (&other != this) {
					Hash::operator=(other);
					KeyEqual::operator=(other);
					GrowthPolicy::operator=(other);

					m_buckets_data = other.m_buckets_data;
					m_buckets =
						m_buckets_data.empty() ? static_empty_bucket_ptr() : m_buckets_data.data();
					m_bucket_count = other.m_bucket_count;
					m_nb_elements = other.m_nb_elements;

					m_load_threshold = other.m_load_threshold;
					m_max_load_factor = other.m_max_load_factor;
					m_grow_on_next_insert = other.m_grow_on_next_insert;

					m_min_load_factor = other.m_min_load_factor;
					m_try_skrink_on_next_insert = other.m_try_skrink_on_next_insert;
				}
				return *this;
			}
			robin_hash &operator=(robin_hash &&other) {
				other.swap(*this);
				other.clear();
				return *this;
			}
			allocator_type get_allocator() const { return m_buckets_data.get_allocator(); }
			iterator begin() noexcept {
				std::size_t i = 0;
				while (i < m_bucket_count && m_buckets[i].empty()) {
					i++;
				}
				return iterator(m_buckets + i);
			}
			const_iterator begin() const noexcept { return cbegin(); }
			const_iterator cbegin() const noexcept {
				std::size_t i = 0;
				while (i < m_bucket_count && m_buckets[i].empty()) {
					i++;
				}

				return const_iterator(m_buckets + i);
			}
			iterator end() noexcept { return iterator(m_buckets + m_bucket_count); }
			const_iterator end() const noexcept { return cend(); }
			const_iterator cend() const noexcept {
				return const_iterator(m_buckets + m_bucket_count);
			}
			bool empty() const noexcept { return m_nb_elements == 0; }
			size_type size() const noexcept { return m_nb_elements; }
			size_type max_size() const noexcept { return m_buckets_data.max_size(); }
			void clear() noexcept {
				for (auto &bucket : m_buckets_data) {
					bucket.clear();
				}
				m_nb_elements = 0;
				m_grow_on_next_insert = false;
			}
			template <typename P> std::pair<iterator, bool> insert(P &&value) {
				return insert_impl(KeySelect()(value), std::forward<P>(value));
			}
			template <typename P> iterator insert_hint(const_iterator hint, P &&value) {
				if (hint != cend() && compare_keys(KeySelect()(*hint), KeySelect()(value))) {
					return mutable_iterator(hint);
				}
				return insert(std::forward<P>(value)).first;
			}
			template <class InputIt> void insert(InputIt first, InputIt last) {
				if (std::is_base_of<
						std::forward_iterator_tag,
						typename std::iterator_traits<InputIt>::iterator_category>::value) {
					const auto nb_elements_insert = std::distance(first, last);
					const size_type nb_free_buckets = m_load_threshold - size();
					if (nb_elements_insert > 0 && nb_free_buckets < size_type(nb_elements_insert)) {
						reserve(size() + size_type(nb_elements_insert));
					}
				}
				for (; first != last; ++first) {
					insert(*first);
				}
			}
			template <class K, class M>
			std::pair<iterator, bool> insert_or_assign(K &&key, M &&obj) {
				auto it = try_emplace(std::forward<K>(key), std::forward<M>(obj));
				if (!it.second) {
					it.first.value() = std::forward<M>(obj);
				}
				return it;
			}
			template <class K, class M>
			iterator insert_or_assign(const_iterator hint, K &&key, M &&obj) {
				if (hint != cend() && compare_keys(KeySelect()(*hint), key)) {
					auto it = mutable_iterator(hint);
					it.value() = std::forward<M>(obj);
					return it;
				}
				return insert_or_assign(std::forward<K>(key), std::forward<M>(obj)).first;
			}
			template <class... Args> std::pair<iterator, bool> emplace(Args &&... args) {
				return insert(value_type(std::forward<Args>(args)...));
			}
			template <class... Args> iterator emplace_hint(const_iterator hint, Args &&... args) {
				return insert_hint(hint, value_type(std::forward<Args>(args)...));
			}
			template <class K, class... Args>
			std::pair<iterator, bool> try_emplace(K &&key, Args &&... args) {
				return insert_impl(key, std::piecewise_construct,
								   std::forward_as_tuple(std::forward<K>(key)),
								   std::forward_as_tuple(std::forward<Args>(args)...));
			}
			template <class K, class... Args>
			iterator try_emplace_hint(const_iterator hint, K &&key, Args &&... args) {
				if (hint != cend() && compare_keys(KeySelect()(*hint), key)) {
					return mutable_iterator(hint);
				}
				return try_emplace(std::forward<K>(key), std::forward<Args>(args)...).first;
			}
			iterator erase(iterator pos) {
				erase_from_bucket(pos);
				if (pos.m_bucket->empty()) {
					++pos;
				}
				m_try_skrink_on_next_insert = true;
				return pos;
			}
			iterator erase(const_iterator pos) { return erase(mutable_iterator(pos)); }
			iterator erase(const_iterator first, const_iterator last) {
				if (first == last) {
					return mutable_iterator(first);
				}
				auto first_mutable = mutable_iterator(first);
				auto last_mutable = mutable_iterator(last);
				for (auto it = first_mutable.m_bucket; it != last_mutable.m_bucket; ++it) {
					if (!it->empty()) {
						it->clear();
						m_nb_elements--;
					}
				}
				if (last_mutable == end()) {
					return end();
				}
				std::size_t icloser_bucket =
					static_cast<std::size_t>(first_mutable.m_bucket - m_buckets);
				std::size_t ito_move_closer_value =
					static_cast<std::size_t>(last_mutable.m_bucket - m_buckets);
				const std::size_t ireturn_bucket =
					ito_move_closer_value -
					std::min(
						ito_move_closer_value - icloser_bucket,
						std::size_t(m_buckets[ito_move_closer_value].dist_from_ideal_bucket()));

				while (ito_move_closer_value < m_bucket_count &&
					   m_buckets[ito_move_closer_value].dist_from_ideal_bucket() > 0) {
					icloser_bucket =
						ito_move_closer_value -
						std::min(
							ito_move_closer_value - icloser_bucket,
							std::size_t(m_buckets[ito_move_closer_value].dist_from_ideal_bucket()));
					const distance_type new_distance =
						distance_type(m_buckets[ito_move_closer_value].dist_from_ideal_bucket() -
									  (ito_move_closer_value - icloser_bucket));
					m_buckets[icloser_bucket].set_value_of_empty_bucket(
						new_distance, m_buckets[ito_move_closer_value].truncated_hash(),
						std::move(m_buckets[ito_move_closer_value].value()));
					m_buckets[ito_move_closer_value].clear();

					++icloser_bucket;
					++ito_move_closer_value;
				}
				m_try_skrink_on_next_insert = true;
				return iterator(m_buckets + ireturn_bucket);
			}
			template <class K> size_type erase(const K &key) { return erase(key, hash_key(key)); }
			template <class K> size_type erase(const K &key, std::size_t hash) {
				auto it = find(key, hash);
				if (it != end()) {
					erase_from_bucket(it);
					m_try_skrink_on_next_insert = true;
					return 1;
				} else {
					return 0;
				}
			}
			void swap(robin_hash &other) {
				using std::swap;
				swap(static_cast<Hash &>(*this), static_cast<Hash &>(other));
				swap(static_cast<KeyEqual &>(*this), static_cast<KeyEqual &>(other));
				swap(static_cast<GrowthPolicy &>(*this), static_cast<GrowthPolicy &>(other));
				swap(m_buckets_data, other.m_buckets_data);
				swap(m_buckets, other.m_buckets);
				swap(m_bucket_count, other.m_bucket_count);
				swap(m_nb_elements, other.m_nb_elements);
				swap(m_load_threshold, other.m_load_threshold);
				swap(m_max_load_factor, other.m_max_load_factor);
				swap(m_grow_on_next_insert, other.m_grow_on_next_insert);
				swap(m_min_load_factor, other.m_min_load_factor);
				swap(m_try_skrink_on_next_insert, other.m_try_skrink_on_next_insert);
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			typename U::value_type &at(const K &key) {
				return at(key, hash_key(key));
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			typename U::value_type &at(const K &key, std::size_t hash) {
				return const_cast<typename U::value_type &>(
					static_cast<const robin_hash *>(this)->at(key, hash));
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			const typename U::value_type &at(const K &key) const {
				return at(key, hash_key(key));
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			const typename U::value_type &at(const K &key, std::size_t hash) const {
				auto it = find(key, hash);
				if (it != cend()) {
					return it.value();
				} else {
					TSL_RH_THROW_OR_TERMINATE(std::out_of_range, "Couldn't find key.");
				}
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			typename U::value_type &operator[](K &&key) {
				return try_emplace(std::forward<K>(key)).first.value();
			}
			template <class K> size_type count(const K &key) const {
				return count(key, hash_key(key));
			}
			template <class K> size_type count(const K &key, std::size_t hash) const {
				if (find(key, hash) != cend()) {
					return 1;
				} else {
					return 0;
				}
			}
			template <class K> iterator find(const K &key) { return find_impl(key, hash_key(key)); }
			template <class K> iterator find(const K &key, std::size_t hash) {
				return find_impl(key, hash);
			}
			template <class K> const_iterator find(const K &key) const {
				return find_impl(key, hash_key(key));
			}
			template <class K> const_iterator find(const K &key, std::size_t hash) const {
				return find_impl(key, hash);
			}
			template <class K> bool contains(const K &key) const {
				return contains(key, hash_key(key));
			}
			template <class K> bool contains(const K &key, std::size_t hash) const {
				return count(key, hash) != 0;
			}
			template <class K> std::pair<iterator, iterator> equal_range(const K &key) {
				return equal_range(key, hash_key(key));
			}
			template <class K>
			std::pair<iterator, iterator> equal_range(const K &key, std::size_t hash) {
				iterator it = find(key, hash);
				return std::make_pair(it, (it == end()) ? it : std::next(it));
			}
			template <class K>
			std::pair<const_iterator, const_iterator> equal_range(const K &key) const {
				return equal_range(key, hash_key(key));
			}
			template <class K>
			std::pair<const_iterator, const_iterator> equal_range(const K &key,
																  std::size_t hash) const {
				const_iterator it = find(key, hash);
				return std::make_pair(it, (it == cend()) ? it : std::next(it));
			}
			size_type bucket_count() const { return m_bucket_count; }
			size_type max_bucket_count() const {
				return std::min(GrowthPolicy::max_bucket_count(), m_buckets_data.max_size());
			}
			float load_factor() const {
				if (bucket_count() == 0) {
					return 0;
				}
				return float(m_nb_elements) / float(bucket_count());
			}
			float min_load_factor() const { return m_min_load_factor; }
			float max_load_factor() const { return m_max_load_factor; }
			void min_load_factor(float ml) {
				m_min_load_factor =
					clamp(ml, float(MINIMUM_MIN_LOAD_FACTOR), float(MAXIMUM_MIN_LOAD_FACTOR));
			}
			void max_load_factor(float ml) {
				m_max_load_factor =
					clamp(ml, float(MINIMUM_MAX_LOAD_FACTOR), float(MAXIMUM_MAX_LOAD_FACTOR));
				m_load_threshold = size_type(float(bucket_count()) * m_max_load_factor);
			}
			void rehash(size_type count) {
				count = std::max(count, size_type(std::ceil(float(size()) / max_load_factor())));
				rehash_impl(count);
			}
			void reserve(size_type count) {
				rehash(size_type(std::ceil(float(count) / max_load_factor())));
			}
			hasher hash_function() const { return static_cast<const Hash &>(*this); }
			key_equal key_eq() const { return static_cast<const KeyEqual &>(*this); }
			iterator mutable_iterator(const_iterator pos) {
				return iterator(const_cast<bucket_entry *>(pos.m_bucket));
			}

		  private:
			template <class K> std::size_t hash_key(const K &key) const {
				return Hash::operator()(key);
			}
			template <class K1, class K2> bool compare_keys(const K1 &key1, const K2 &key2) const {
				return KeyEqual::operator()(key1, key2);
			}
			std::size_t bucket_for_hash(std::size_t hash) const {
				const std::size_t bucket = GrowthPolicy::bucket_for_hash(hash);
				return bucket;
			}
			template <class U = GrowthPolicy,
					  typename std::enable_if<is_power_of_two_policy<U>::value>::type * = nullptr>
			std::size_t next_bucket(std::size_t index) const noexcept {
				return (index + 1) & this->m_mask;
			}
			template <class U = GrowthPolicy,
					  typename std::enable_if<!is_power_of_two_policy<U>::value>::type * = nullptr>
			std::size_t next_bucket(std::size_t index) const noexcept {
				index++;
				return (index != bucket_count()) ? index : 0;
			}
			template <class K> iterator find_impl(const K &key, std::size_t hash) {
				return mutable_iterator(static_cast<const robin_hash *>(this)->find(key, hash));
			}
			template <class K> const_iterator find_impl(const K &key, std::size_t hash) const {
				std::size_t ibucket = bucket_for_hash(hash);
				distance_type dist_from_ideal_bucket = 0;
				while (dist_from_ideal_bucket <= m_buckets[ibucket].dist_from_ideal_bucket()) {
					if (TSL_RH_LIKELY((!USE_STORED_HASH_ON_LOOKUP ||
									   m_buckets[ibucket].bucket_hash_equal(hash)) &&
									  compare_keys(KeySelect()(m_buckets[ibucket].value()), key))) {
						return const_iterator(m_buckets + ibucket);
					}

					ibucket = next_bucket(ibucket);
					dist_from_ideal_bucket++;
				}
				return cend();
			}
			void erase_from_bucket(iterator pos) {
				pos.m_bucket->clear();
				m_nb_elements--;
				std::size_t previous_ibucket = static_cast<std::size_t>(pos.m_bucket - m_buckets);
				std::size_t ibucket = next_bucket(previous_ibucket);

				while (m_buckets[ibucket].dist_from_ideal_bucket() > 0) {
					const distance_type new_distance =
						distance_type(m_buckets[ibucket].dist_from_ideal_bucket() - 1);
					m_buckets[previous_ibucket].set_value_of_empty_bucket(
						new_distance, m_buckets[ibucket].truncated_hash(),
						std::move(m_buckets[ibucket].value()));
					m_buckets[ibucket].clear();

					previous_ibucket = ibucket;
					ibucket = next_bucket(ibucket);
				}
			}
			template <class K, class... Args>
			std::pair<iterator, bool> insert_impl(const K &key, Args &&... value_type_args) {
				const std::size_t hash = hash_key(key);
				std::size_t ibucket = bucket_for_hash(hash);
				distance_type dist_from_ideal_bucket = 0;
				while (dist_from_ideal_bucket <= m_buckets[ibucket].dist_from_ideal_bucket()) {
					if ((!USE_STORED_HASH_ON_LOOKUP ||
						 m_buckets[ibucket].bucket_hash_equal(hash)) &&
						compare_keys(KeySelect()(m_buckets[ibucket].value()), key)) {
						return std::make_pair(iterator(m_buckets + ibucket), false);
					}

					ibucket = next_bucket(ibucket);
					dist_from_ideal_bucket++;
				}
				if (rehash_on_extreme_load()) {
					ibucket = bucket_for_hash(hash);
					dist_from_ideal_bucket = 0;

					while (dist_from_ideal_bucket <= m_buckets[ibucket].dist_from_ideal_bucket()) {
						ibucket = next_bucket(ibucket);
						dist_from_ideal_bucket++;
					}
				}
				if (m_buckets[ibucket].empty()) {
					m_buckets[ibucket].set_value_of_empty_bucket(
						dist_from_ideal_bucket, bucket_entry::truncate_hash(hash),
						std::forward<Args>(value_type_args)...);
				} else {
					insert_value(ibucket, dist_from_ideal_bucket, bucket_entry::truncate_hash(hash),
								 std::forward<Args>(value_type_args)...);
				}
				m_nb_elements++;
				return std::make_pair(iterator(m_buckets + ibucket), true);
			}

			template <class... Args>
			void insert_value(std::size_t ibucket, distance_type dist_from_ideal_bucket,
							  truncated_hash_type hash, Args &&... value_type_args) {
				value_type value(std::forward<Args>(value_type_args)...);
				insert_value_impl(ibucket, dist_from_ideal_bucket, hash, value);
			}

			void insert_value(std::size_t ibucket, distance_type dist_from_ideal_bucket,
							  truncated_hash_type hash, value_type &&value) {
				insert_value_impl(ibucket, dist_from_ideal_bucket, hash, value);
			}
			void insert_value_impl(std::size_t ibucket, distance_type dist_from_ideal_bucket,
								   truncated_hash_type hash, value_type &value) {
				m_buckets[ibucket].swap_with_value_in_bucket(dist_from_ideal_bucket, hash, value);
				ibucket = next_bucket(ibucket);
				dist_from_ideal_bucket++;
				while (!m_buckets[ibucket].empty()) {
					if (dist_from_ideal_bucket > m_buckets[ibucket].dist_from_ideal_bucket()) {
						if (dist_from_ideal_bucket >= bucket_entry::DIST_FROM_IDEAL_BUCKET_LIMIT) {
							m_grow_on_next_insert = true;
						}
						m_buckets[ibucket].swap_with_value_in_bucket(dist_from_ideal_bucket, hash,
																	 value);
					}
					ibucket = next_bucket(ibucket);
					dist_from_ideal_bucket++;
				}
				m_buckets[ibucket].set_value_of_empty_bucket(dist_from_ideal_bucket, hash,
															 std::move(value));
			}
			void rehash_impl(size_type count) {
				robin_hash new_table(count, static_cast<Hash &>(*this),
									 static_cast<KeyEqual &>(*this), get_allocator(),
									 m_min_load_factor, m_max_load_factor);

				const bool use_stored_hash = USE_STORED_HASH_ON_REHASH(new_table.bucket_count());
				for (auto &bucket : m_buckets_data) {
					if (bucket.empty()) {
						continue;
					}

					const std::size_t hash = use_stored_hash
												 ? bucket.truncated_hash()
												 : new_table.hash_key(KeySelect()(bucket.value()));

					new_table.insert_value_on_rehash(new_table.bucket_for_hash(hash), 0,
													 bucket_entry::truncate_hash(hash),
													 std::move(bucket.value()));
				}

				new_table.m_nb_elements = m_nb_elements;
				new_table.swap(*this);
			}

			void insert_value_on_rehash(std::size_t ibucket, distance_type dist_from_ideal_bucket,
										truncated_hash_type hash, value_type &&value) {
				while (true) {
					if (dist_from_ideal_bucket > m_buckets[ibucket].dist_from_ideal_bucket()) {
						if (m_buckets[ibucket].empty()) {
							m_buckets[ibucket].set_value_of_empty_bucket(dist_from_ideal_bucket,
																		 hash, std::move(value));
							return;
						} else {
							m_buckets[ibucket].swap_with_value_in_bucket(dist_from_ideal_bucket,
																		 hash, value);
						}
					}

					dist_from_ideal_bucket++;
					ibucket = next_bucket(ibucket);
				}
			}
			bool rehash_on_extreme_load() {
				if (m_grow_on_next_insert || size() >= m_load_threshold) {
					rehash_impl(GrowthPolicy::next_bucket_count());
					m_grow_on_next_insert = false;

					return true;
				}
				if (m_try_skrink_on_next_insert) {
					m_try_skrink_on_next_insert = false;
					if (m_min_load_factor != 0.0f && load_factor() < m_min_load_factor) {
						reserve(size() + 1);

						return true;
					}
				}

				return false;
			}

		  public:
			static const size_type DEFAULT_INIT_BUCKETS_SIZE = 0;
			static constexpr float DEFAULT_MAX_LOAD_FACTOR = 0.5f;
			static constexpr float MINIMUM_MAX_LOAD_FACTOR = 0.2f;
			static constexpr float MAXIMUM_MAX_LOAD_FACTOR = 0.95f;
			static constexpr float DEFAULT_MIN_LOAD_FACTOR = 0.0f;
			static constexpr float MINIMUM_MIN_LOAD_FACTOR = 0.0f;
			static constexpr float MAXIMUM_MIN_LOAD_FACTOR = 0.15f;
			static_assert(MINIMUM_MAX_LOAD_FACTOR < MAXIMUM_MAX_LOAD_FACTOR,
						  "MINIMUM_MAX_LOAD_FACTOR should be < MAXIMUM_MAX_LOAD_FACTOR");
			static_assert(MINIMUM_MIN_LOAD_FACTOR < MAXIMUM_MIN_LOAD_FACTOR,
						  "MINIMUM_MIN_LOAD_FACTOR should be < MAXIMUM_MIN_LOAD_FACTOR");
			static_assert(MAXIMUM_MIN_LOAD_FACTOR < MINIMUM_MAX_LOAD_FACTOR,
						  "MAXIMUM_MIN_LOAD_FACTOR should be < MINIMUM_MAX_LOAD_FACTOR");

		  private:
			bucket_entry *static_empty_bucket_ptr() {
				static bucket_entry empty_bucket(true);
				return &empty_bucket;
			}

		  private:
			buckets_container_type m_buckets_data;
			bucket_entry *m_buckets;
			size_type m_bucket_count;
			size_type m_nb_elements;
			size_type m_load_threshold;
			float m_max_load_factor;
			bool m_grow_on_next_insert;
			float m_min_load_factor;
			bool m_try_skrink_on_next_insert;
		};

	} // namespace detail_robin_hash

} // namespace tsl

namespace tsl {
	template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>,
			  class Allocator = std::allocator<std::pair<Key, T>>, bool StoreHash = false,
			  class GrowthPolicy = tsl::rh::power_of_two_growth_policy<2>>
	class robin_map {
	  private:
		template <typename U>
		using has_is_transparent = tsl::detail_robin_hash::has_is_transparent<U>;
		class KeySelect {
		  public:
			using key_type = Key;

			const key_type &operator()(const std::pair<Key, T> &key_value) const noexcept {
				return key_value.first;
			}

			key_type &operator()(std::pair<Key, T> &key_value) noexcept { return key_value.first; }
		};
		class ValueSelect {
		  public:
			using value_type = T;

			const value_type &operator()(const std::pair<Key, T> &key_value) const noexcept {
				return key_value.second;
			}

			value_type &operator()(std::pair<Key, T> &key_value) noexcept {
				return key_value.second;
			}
		};
		using ht = detail_robin_hash::robin_hash<std::pair<Key, T>, KeySelect, ValueSelect, Hash,
												 KeyEqual, Allocator, StoreHash, GrowthPolicy>;

	  public:
		using key_type = typename ht::key_type;
		using mapped_type = T;
		using value_type = typename ht::value_type;
		using size_type = typename ht::size_type;
		using difference_type = typename ht::difference_type;
		using hasher = typename ht::hasher;
		using key_equal = typename ht::key_equal;
		using allocator_type = typename ht::allocator_type;
		using reference = typename ht::reference;
		using const_reference = typename ht::const_reference;
		using pointer = typename ht::pointer;
		using const_pointer = typename ht::const_pointer;
		using iterator = typename ht::iterator;
		using const_iterator = typename ht::const_iterator;

	  public:
		robin_map() : robin_map(ht::DEFAULT_INIT_BUCKETS_SIZE) {}

		explicit robin_map(size_type bucket_count, const Hash &hash = Hash(),
						   const KeyEqual &equal = KeyEqual(), const Allocator &alloc = Allocator())
			: m_ht(bucket_count, hash, equal, alloc) {}

		robin_map(size_type bucket_count, const Allocator &alloc)
			: robin_map(bucket_count, Hash(), KeyEqual(), alloc) {}

		robin_map(size_type bucket_count, const Hash &hash, const Allocator &alloc)
			: robin_map(bucket_count, hash, KeyEqual(), alloc) {}

		explicit robin_map(const Allocator &alloc)
			: robin_map(ht::DEFAULT_INIT_BUCKETS_SIZE, alloc) {}

		template <class InputIt>
		robin_map(InputIt first, InputIt last,
				  size_type bucket_count = ht::DEFAULT_INIT_BUCKETS_SIZE, const Hash &hash = Hash(),
				  const KeyEqual &equal = KeyEqual(), const Allocator &alloc = Allocator())
			: robin_map(bucket_count, hash, equal, alloc) {
			insert(first, last);
		}

		template <class InputIt>
		robin_map(InputIt first, InputIt last, size_type bucket_count, const Allocator &alloc)
			: robin_map(first, last, bucket_count, Hash(), KeyEqual(), alloc) {}

		template <class InputIt>
		robin_map(InputIt first, InputIt last, size_type bucket_count, const Hash &hash,
				  const Allocator &alloc)
			: robin_map(first, last, bucket_count, hash, KeyEqual(), alloc) {}

		robin_map(std::initializer_list<value_type> init,
				  size_type bucket_count = ht::DEFAULT_INIT_BUCKETS_SIZE, const Hash &hash = Hash(),
				  const KeyEqual &equal = KeyEqual(), const Allocator &alloc = Allocator())
			: robin_map(init.begin(), init.end(), bucket_count, hash, equal, alloc) {}

		robin_map(std::initializer_list<value_type> init, size_type bucket_count,
				  const Allocator &alloc)
			: robin_map(init.begin(), init.end(), bucket_count, Hash(), KeyEqual(), alloc) {}

		robin_map(std::initializer_list<value_type> init, size_type bucket_count, const Hash &hash,
				  const Allocator &alloc)
			: robin_map(init.begin(), init.end(), bucket_count, hash, KeyEqual(), alloc) {}

		robin_map &operator=(std::initializer_list<value_type> ilist) {
			m_ht.clear();

			m_ht.reserve(ilist.size());
			m_ht.insert(ilist.begin(), ilist.end());

			return *this;
		}

		allocator_type get_allocator() const { return m_ht.get_allocator(); }
		iterator begin() noexcept { return m_ht.begin(); }
		const_iterator begin() const noexcept { return m_ht.begin(); }
		const_iterator cbegin() const noexcept { return m_ht.cbegin(); }
		iterator end() noexcept { return m_ht.end(); }
		const_iterator end() const noexcept { return m_ht.end(); }
		const_iterator cend() const noexcept { return m_ht.cend(); }
		bool empty() const noexcept { return m_ht.empty(); }
		size_type size() const noexcept { return m_ht.size(); }
		size_type max_size() const noexcept { return m_ht.max_size(); }
		void clear() noexcept { m_ht.clear(); }
		std::pair<iterator, bool> insert(const value_type &value) { return m_ht.insert(value); }
		template <class P, typename std::enable_if<
							   std::is_constructible<value_type, P &&>::value>::type * = nullptr>
		std::pair<iterator, bool> insert(P &&value) {
			return m_ht.emplace(std::forward<P>(value));
		}
		std::pair<iterator, bool> insert(value_type &&value) {
			return m_ht.insert(std::move(value));
		}
		iterator insert(const_iterator hint, const value_type &value) {
			return m_ht.insert_hint(hint, value);
		}
		template <class P, typename std::enable_if<
							   std::is_constructible<value_type, P &&>::value>::type * = nullptr>
		iterator insert(const_iterator hint, P &&value) {
			return m_ht.emplace_hint(hint, std::forward<P>(value));
		}
		iterator insert(const_iterator hint, value_type &&value) {
			return m_ht.insert_hint(hint, std::move(value));
		}
		template <class InputIt> void insert(InputIt first, InputIt last) {
			m_ht.insert(first, last);
		}
		void insert(std::initializer_list<value_type> ilist) {
			m_ht.insert(ilist.begin(), ilist.end());
		}
		template <class M> std::pair<iterator, bool> insert_or_assign(const key_type &k, M &&obj) {
			return m_ht.insert_or_assign(k, std::forward<M>(obj));
		}
		template <class M> std::pair<iterator, bool> insert_or_assign(key_type &&k, M &&obj) {
			return m_ht.insert_or_assign(std::move(k), std::forward<M>(obj));
		}
		template <class M>
		iterator insert_or_assign(const_iterator hint, const key_type &k, M &&obj) {
			return m_ht.insert_or_assign(hint, k, std::forward<M>(obj));
		}
		template <class M> iterator insert_or_assign(const_iterator hint, key_type &&k, M &&obj) {
			return m_ht.insert_or_assign(hint, std::move(k), std::forward<M>(obj));
		}
		template <class... Args> std::pair<iterator, bool> emplace(Args &&... args) {
			return m_ht.emplace(std::forward<Args>(args)...);
		}
		template <class... Args> iterator emplace_hint(const_iterator hint, Args &&... args) {
			return m_ht.emplace_hint(hint, std::forward<Args>(args)...);
		}
		template <class... Args>
		std::pair<iterator, bool> try_emplace(const key_type &k, Args &&... args) {
			return m_ht.try_emplace(k, std::forward<Args>(args)...);
		}
		template <class... Args>
		std::pair<iterator, bool> try_emplace(key_type &&k, Args &&... args) {
			return m_ht.try_emplace(std::move(k), std::forward<Args>(args)...);
		}
		template <class... Args>
		iterator try_emplace(const_iterator hint, const key_type &k, Args &&... args) {
			return m_ht.try_emplace_hint(hint, k, std::forward<Args>(args)...);
		}
		template <class... Args>
		iterator try_emplace(const_iterator hint, key_type &&k, Args &&... args) {
			return m_ht.try_emplace_hint(hint, std::move(k), std::forward<Args>(args)...);
		}
		iterator erase(iterator pos) { return m_ht.erase(pos); }
		iterator erase(const_iterator pos) { return m_ht.erase(pos); }
		iterator erase(const_iterator first, const_iterator last) {
			return m_ht.erase(first, last);
		}
		size_type erase(const key_type &key) { return m_ht.erase(key); }
		size_type erase(const key_type &key, std::size_t precalculated_hash) {
			return m_ht.erase(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type erase(const K &key) {
			return m_ht.erase(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type erase(const K &key, std::size_t precalculated_hash) {
			return m_ht.erase(key, precalculated_hash);
		}
		void swap(robin_map &other) { other.m_ht.swap(m_ht); }
		T &at(const Key &key) { return m_ht.at(key); }
		T &at(const Key &key, std::size_t precalculated_hash) {
			return m_ht.at(key, precalculated_hash);
		}
		const T &at(const Key &key) const { return m_ht.at(key); }
		const T &at(const Key &key, std::size_t precalculated_hash) const {
			return m_ht.at(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		T &at(const K &key) {
			return m_ht.at(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		T &at(const K &key, std::size_t precalculated_hash) {
			return m_ht.at(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const T &at(const K &key) const {
			return m_ht.at(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const T &at(const K &key, std::size_t precalculated_hash) const {
			return m_ht.at(key, precalculated_hash);
		}

		T &operator[](const Key &key) { return m_ht[key]; }
		T &operator[](Key &&key) { return m_ht[std::move(key)]; }

		size_type count(const Key &key) const { return m_ht.count(key); }
		size_type count(const Key &key, std::size_t precalculated_hash) const {
			return m_ht.count(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type count(const K &key) const {
			return m_ht.count(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type count(const K &key, std::size_t precalculated_hash) const {
			return m_ht.count(key, precalculated_hash);
		}
		iterator find(const Key &key) { return m_ht.find(key); }
		iterator find(const Key &key, std::size_t precalculated_hash) {
			return m_ht.find(key, precalculated_hash);
		}
		const_iterator find(const Key &key) const { return m_ht.find(key); }
		const_iterator find(const Key &key, std::size_t precalculated_hash) const {
			return m_ht.find(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		iterator find(const K &key) {
			return m_ht.find(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		iterator find(const K &key, std::size_t precalculated_hash) {
			return m_ht.find(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const_iterator find(const K &key) const {
			return m_ht.find(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const_iterator find(const K &key, std::size_t precalculated_hash) const {
			return m_ht.find(key, precalculated_hash);
		}
		bool contains(const Key &key) const { return m_ht.contains(key); }
		bool contains(const Key &key, std::size_t precalculated_hash) const {
			return m_ht.contains(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		bool contains(const K &key) const {
			return m_ht.contains(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		bool contains(const K &key, std::size_t precalculated_hash) const {
			return m_ht.contains(key, precalculated_hash);
		}
		std::pair<iterator, iterator> equal_range(const Key &key) { return m_ht.equal_range(key); }
		std::pair<iterator, iterator> equal_range(const Key &key, std::size_t precalculated_hash) {
			return m_ht.equal_range(key, precalculated_hash);
		}
		std::pair<const_iterator, const_iterator> equal_range(const Key &key) const {
			return m_ht.equal_range(key);
		}
		std::pair<const_iterator, const_iterator>
		equal_range(const Key &key, std::size_t precalculated_hash) const {
			return m_ht.equal_range(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<iterator, iterator> equal_range(const K &key) {
			return m_ht.equal_range(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<iterator, iterator> equal_range(const K &key, std::size_t precalculated_hash) {
			return m_ht.equal_range(key, precalculated_hash);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<const_iterator, const_iterator> equal_range(const K &key) const {
			return m_ht.equal_range(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<const_iterator, const_iterator>
		equal_range(const K &key, std::size_t precalculated_hash) const {
			return m_ht.equal_range(key, precalculated_hash);
		}
		size_type bucket_count() const { return m_ht.bucket_count(); }
		size_type max_bucket_count() const { return m_ht.max_bucket_count(); }
		float load_factor() const { return m_ht.load_factor(); }
		float min_load_factor() const { return m_ht.min_load_factor(); }
		float max_load_factor() const { return m_ht.max_load_factor(); }
		void min_load_factor(float ml) { m_ht.min_load_factor(ml); }
		void max_load_factor(float ml) { m_ht.max_load_factor(ml); }
		void rehash(size_type count) { m_ht.rehash(count); }
		void reserve(size_type count) { m_ht.reserve(count); }
		hasher hash_function() const { return m_ht.hash_function(); }
		key_equal key_eq() const { return m_ht.key_eq(); }
		iterator mutable_iterator(const_iterator pos) { return m_ht.mutable_iterator(pos); }
		friend bool operator==(const robin_map &lhs, const robin_map &rhs) {
			if (lhs.size() != rhs.size()) {
				return false;
			}

			for (const auto &element_lhs : lhs) {
				const auto it_element_rhs = rhs.find(element_lhs.first);
				if (it_element_rhs == rhs.cend() || element_lhs.second != it_element_rhs->second) {
					return false;
				}
			}

			return true;
		}

		friend bool operator!=(const robin_map &lhs, const robin_map &rhs) {
			return !operator==(lhs, rhs);
		}

		friend void swap(robin_map &lhs, robin_map &rhs) { lhs.swap(rhs); }

	  private:
		ht m_ht;
	};
	template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>,
			  class Allocator = std::allocator<std::pair<Key, T>>, bool StoreHash = false>
	using robin_pg_map =
		robin_map<Key, T, Hash, KeyEqual, Allocator, StoreHash, tsl::rh::prime_growth_policy>;

} // end namespace tsl



#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
const int N = 3e5 + 5;
int n, k;
ll a[N];
int le[N], ri[N];
ll ans = 0;
 
// ma[val] = how many times val + offset appears
 
struct orz {
    tsl::robin_map<int, int> ma;
    ll off, sum;
    pmr::list<ll> ve;
    orz() {
        ma[0]++;
        off = 0;
        sum = 0;
    }
    void push_back(ll val) {
        val %= k;
        ve.push_back(val);
        sum += val;
        ma[(sum + off) % k]++;
    }
    void push_front(ll val) {
        val %= k;
        ve.push_front(val);
        sum += val;
        off = (off + k - val) % k;
        ma[off]++;
    }
    int countpref(ll val) {
        return ma[((val + off) % k + k) % k];
    }
    int countsuff(ll val) {
        val = ((sum - val + off) % k + k) % k;
        return ma[val];
    }
    size_t size() {
        return ve.size();
    }
};

 
orz solve(int root) {
    if(root == 0) {
        return {};
    }
    orz A = solve(le[root]);
    orz B = solve(ri[root]);
    if(sz(A) > sz(B)) {
        ll sum = 0;
        ans += A.countsuff(sum);
        for(ll x : B.ve) {
            sum += x;
            ans += A.countsuff(k - sum);
        }
        A.push_back(a[root]);
        for(ll x : B.ve) {
            A.push_back(x);
        }
        return A;
    }else {
        ll sum = 0;
        reverse(all(A.ve));
        ans += B.countpref(sum);
        for(ll x : A.ve) {
            sum += x;
            ans += B.countpref(k - sum);
        }
        B.push_front(a[root]);
        for(ll x : A.ve) {
            B.push_front(x);
        }
        return B;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	pmr::monotonic_buffer_resource rsc(pmr::new_delete_resource());
	pmr::set_default_resource(&rsc);

    cin >> n >> k;
    vector<pii> ve;
    rep(i, 1, n + 1) {
        cin >> a[i];
        ve.emplace_back(-a[i], i);
    }
    sort(all(ve));
    set<int> se;
    int root = ve[0].second;
    se.insert(root);
 
    for(int idx = 1; idx < sz(ve); idx++) {
        int i = ve[idx].second;
        auto it = se.lower_bound(i);
        if(it == se.end()) {
            // parent to the left
            ri[*prev(it)] = i;
        }else if(it == se.begin()) {
            // parent to the right
            le[*it] = i;
        }else {
            // compare
            if(a[*prev(it)] >= a[*it]) {
                le[*it] = i;
            }else {
                ri[*prev(it)] = i;
            }
        }
        se.insert(i);
    }
    solve(root);
    ans -= n;
    cout << ans << '\n';
}