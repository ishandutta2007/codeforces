#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

constexpr int kMaxValue = 15000001;
constexpr int kMaxFactorization = 25;

class Factorizator {
  public:
    Factorizator() : prime_divisors_num_(0),
                     prime_divisors_(kMaxFactorization),
                     next_distinct_prime_divisors_(kMaxFactorization) {}

    void Reset() {
        prime_divisors_num_ = 0;
    }

    void Add(int prime_divisor) {
        prime_divisors_[prime_divisors_num_++] = prime_divisor;
    }

    void ApplyToAllDivisors(const std::function<void(int)>& functor) {
        std::sort(prime_divisors_.begin(), prime_divisors_.begin() + prime_divisors_num_);

        int next_distinct_prime_divisor = prime_divisors_num_;
        for (int i = prime_divisors_num_ - 1; i >= 0; i--) {
            if (i + 1 < prime_divisors_num_ && prime_divisors_[i] < prime_divisors_[i + 1]) {
                next_distinct_prime_divisor = i + 1;
            }

            next_distinct_prime_divisors_[i] = next_distinct_prime_divisor;
        }

        ApplyToAllDivisorsRecursively(1, 0, functor);
    }

  private:
    void ApplyToAllDivisorsRecursively(int divisor, int position, const std::function<void(int)>& functor) {
        if (position == prime_divisors_num_) {
            functor(divisor);
            return;
        }

        ApplyToAllDivisorsRecursively(divisor, next_distinct_prime_divisors_[position], functor);
        ApplyToAllDivisorsRecursively(divisor * prime_divisors_[position], position + 1, functor);
    }

    int prime_divisors_num_;
    std::vector<int> prime_divisors_;
    std::vector<int> next_distinct_prime_divisors_;
};

void Solve() {
    std::vector<int> multiplies_count(kMaxValue, 0);
    std::vector<int> prime_divisors(kMaxValue, -1);

    // Pre-compute prime divisors for all integers up to kMaxValue.
    for (int i = 2; i * i < kMaxValue; ++i) {
        if (prime_divisors[i] > -1) {
            continue;
        }

        for (int j = i * i; j < kMaxValue; j += i) {
            prime_divisors[j] = i;
        }
    }

    int n; std::cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    std::sort(values.begin(), values.end());

    std::vector<int> next_values(n);
    next_values[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        if (values[i] < values[i + 1]) {
            next_values[i] = i + 1;
        } else {
            next_values[i] = next_values[i + 1];
        }
    }

    Factorizator factorizator;

    int position = 0;
    while (position < n) {
        int value = values[position];
        int values_num = next_values[position] - position;

        factorizator.Reset();
        while (value > 1) {
            if (prime_divisors[value] == -1) {
                factorizator.Add(value);
                break;
            }

            factorizator.Add(prime_divisors[value]);
            value /= prime_divisors[value];
        }

        factorizator.ApplyToAllDivisors(
            [&multiplies_count, values_num](int x) {
                multiplies_count[x] += values_num;
            });

        position = next_values[position];
    }

    int min_values_to_remove = -1;
    for (int g = 1; g < kMaxValue; ++g) {
        if (multiplies_count[g] == n) {
            min_values_to_remove = -1;
            continue;
        }

        if (multiplies_count[g] == 0) {
            continue;
        }

        if (min_values_to_remove == -1) {
            min_values_to_remove = n - multiplies_count[g];
        } else {
            min_values_to_remove = std::min(min_values_to_remove, n - multiplies_count[g]);
        }
    }

    std::cout << min_values_to_remove << "\n";
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(0);
    Solve();
    return 0;
}