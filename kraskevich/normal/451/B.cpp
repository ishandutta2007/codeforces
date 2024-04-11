#include <bits/stdc++.h>

using namespace std;

namespace data_structures {
  //Forward declaration of the SkipList class.
  template<class T, class LESS=std::less<T>, class ALLOC=std::allocator<T>, int H=20u>
  class SkipList;

  /**
   *A node in a list.
   *It constains actual data and pointers to
   *prevoius and next nodes.
   */
  template<class T>
  struct Node {
    T data;
    std::vector<Node*> next;
    std::vector<Node*> prev;
  };

  /**
   *Skip list bidirectional iterator.
   *Data pointed by this iterator cannot be modified.
   */
  template<class T>
  struct Iterator {
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef size_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;

    /**
     *Merely copies the value of the pointer.
     */
    Iterator(const Node<T>* _data): data(_data) {}

    /**
     *Moves to the next element of the list.
     */
    Iterator& operator++() { //prefix
      data = data->next[0];
      return *this;
    }

    /**
     *Moves to the previous element of the list.
     */
    Iterator& operator--() { //prefix
      data = data->prev[0];
      return *this;
    }

    /**
     *Moves to the next element of the list.
     */
    Iterator operator++(int) { //postfix
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    /**
     *Moves to the previous element of the list.
     */
    Iterator operator--(int) { //postfix
      Iterator temp = *this;
      --(*this);
      return temp;
    }

    /**
     *Returns a const refernce to the data pointed by
     *this iterator.
     */
    const T& operator*() const {
      return data->data;
    }

    /**
     *Compares the value of data pointer.
     */
    bool operator == (const Iterator &rhs) {
      return data == rhs.data;
    }

    /**
     *Compares the value of data pointer.
     */
    bool operator != (const Iterator &rhs) {
      return !(*this == rhs);
    }

    template<class U, class LESS, class ALLOC, int H>
    friend class SkipList;

    private:
      const Node<T>* data;
  };

  /**
   *Skip list implementation.
   */
  template<class T, class LESS, class ALLOC, int H>
  class SkipList {
    static_assert(H > 0, "maximum height must be positive");
  public:
    typedef T value_type;
    typedef Iterator<T> iterator;
    typedef Iterator<T> const_iterator;

    /**
     *Creates an empty skip list.
     */
    SkipList();

    /**
     *Creates a skip list by adding all elements
     *from [first, last) range.
     *first and last shoild be pointers
     *or iterators.
     */
    template<class I>
    SkipList(I first, I last): SkipList() {
      while (first != last)
        insert(*first++);
    }

    /**
     *Creates a copy of rhs list.
     */
    SkipList(const SkipList& rhs): SkipList(rhs.begin(), rhs.end()) {}

    /**
     *Creates a copy of rhs list.
     */
    SkipList& operator = (const SkipList& rhs) {
      (*this)(rhs.begin(), rhs.end());
      return *this;
    }

    /**
     *Destroys the list.
     *Releases all used memory.
     */
    ~SkipList();

    /**
     *Returns an iterator pointing to the first element of the list.
     */
    iterator begin() const {
      iterator iter = iterator(&first);
      return ++iter;
    }

    /**
     *Returns an iterator pointing to the element after the last one.
     */
    iterator end() const {
      return iterator(&last);
    }

    /**
     *Returns a reverse iterator pointing to last element of the list.
     */
    std::reverse_iterator<iterator> rbegin() const {
      return std::reverse_iterator<iterator>(end());
    }

    /**
     *Returns a reverse iterator pointing to the element before the
     *first one.
     */
    std::reverse_iterator<iterator> rend() const {
      return std::reverse_iterator<iterator>(begin());
    }

    /**
     *Returns the size of the list.
     */
    size_t size() {
      return _size;
    }

    /**
     *Inserts value into the list.
     *Duplicates are ignored.
     */
    void insert(const T& value);

    /**
     *Returns 1 if value is in this list and 0 otherwise.
     */
    int count(const T& value) const {
      return find(value) != end() ? 1 : 0;
    }

    /**
     *Returns an iterator pointing to the element with value
     *if it is in this list and end() otherwise.
     */
    iterator find(const T& value) const {
      auto iter = lower_bound(value);
      if (iter == end() || *iter != value)
        return end();
      return iter;
    }

    /**
     *Returns an iterator pointing to the first element which is not less
     *than value.
     */
    iterator lower_bound(const T& value) const;

    /**
     *Returns an iterator pointing to the first element such that value
     *is less than it.
     */
    iterator upper_bound(const T& value) const;

    /**
     *Removes value from the list.
     *If value is not present in this list does nothing.
     */
    void erase(const T& value);

  private:
    //Beginning of the list.
    Node<T> first;
    //End of the list.
    Node<T> last;
    //Allocator.
    typename ALLOC::template rebind<Node<T>>::other alloc;
    //Comparator.
    LESS _less;
    //Number of elements in the list.
    size_t _size;

    /**
     *Randomized algorithm to detirmine node's level.
     */
    int get_height() {
      int h = 1;
      while (h < H && (rand() & 1))
        h++;
      return h;
    }
  };

  template<class T, class LESS, class ALLOC, int H>
  SkipList<T, LESS, ALLOC, H>::SkipList() {
    _size = 0;
    first.next.assign(H, &last);
    first.prev.assign(H, nullptr);
    last.next.assign(H, nullptr);
    last.prev.assign(H, &first);
  }

  template<class T, class LESS, class ALLOC, int H>
  SkipList<T, LESS, ALLOC, H>::~SkipList() {
    Node<T>* cur = &first;
    Node<T>* next = first.next[0];
    while (next != &last) {
      cur = next;
      next = cur->next[0];
      alloc.destroy(cur);
      alloc.deallocate(cur, 1);
    }
  }

  template<class T, class LESS, class ALLOC, int H>
  void SkipList<T, LESS, ALLOC, H>::insert(const T& value) {
    if (count(value))
      return;
    _size++;
    Node<T>* cur = &first;
    Node<T>* node = alloc.allocate(1);
    alloc.construct(node);
    node->data = value;
    int cur_h = get_height();
    int h = H - 1;
    node->next.assign(cur_h, nullptr);
    node->prev.assign(cur_h, nullptr);
    std::vector<Node<T>*> lower(H);
    while (h >= 0) {
      bool running = true;
      do {
        bool next_bigger = false;
        if (cur->next[h] == &last)
          next_bigger = true;
        else if (_less(value, cur->next[h]->data))
          next_bigger = true;
        if (next_bigger)
          running = false;
        else
          cur = cur->next[h];
      } while(running);
      lower[h] = cur;
      h--;
    }
    for (int level = 0; level < cur_h; level++) {
      Node<T>* left = lower[level];
      Node<T>* right = lower[level]->next[level];
      left->next[level] = node;
      right->prev[level] = node;
      node->prev[level] = left;
      node->next[level] = right;
    }
  }

  template<class T, class LESS, class ALLOC, int H>
  typename SkipList<T, LESS, ALLOC, H>::iterator
  SkipList<T, LESS, ALLOC, H>::lower_bound(const T& value) const {
    Node<T>* cur = const_cast<Node<T>*>(&first);
    int h = H - 1;
    while (h >= 0) {
      bool running = true;
      do {
        bool next_bigger = false;
        if (cur->next[h] == &last)
          next_bigger = true;
        else if (!_less(cur->next[h]->data, value))
          next_bigger = true;
        if (next_bigger)
          running = false;
        else
          cur = cur->next[h];
      } while(running);
      h--;
    }
    cur = cur->next[0];
    return iterator(cur);
  }


  template<class T, class LESS, class ALLOC, int H>
  typename SkipList<T, LESS, ALLOC, H>::iterator
  SkipList<T, LESS, ALLOC, H>::upper_bound(const T& value) const {
    Node<T>* cur = const_cast<Node<T>*>(&first);
    int h = H - 1;
    while (h >= 0) {
      bool running = true;
      do {
        bool next_bigger = false;
        if (cur->next[h] == &last)
          next_bigger = true;
        else if (_less(value, cur->next[h]->data))
          next_bigger = true;
        if (next_bigger)
          running = false;
        else
          cur = cur->next[h];
      } while(running);
      h--;
    }
    cur = cur->next[0];
    return iterator(cur);
  }


  template<class T, class LESS, class ALLOC, int H>
  void SkipList<T, LESS, ALLOC, H>::erase(const T& value) {
    if (!count(value))
      return;
    _size--;
    Node<T>* cur = &first;
    int h = H - 1;
    while (h >= 0) {
      bool running = true;
      do {
        bool next_bigger = false;
        if (cur->next[h] == &last)
          next_bigger = true;
        else if (!_less(cur->next[h]->data, value))
          next_bigger = true;
        if (next_bigger)
          running = false;
        else
          cur = cur->next[h];
      } while(running);
      h--;
    }
    cur = cur->next[0];
    for (int level = 0; level < (int)cur->next.size(); level++) {
      Node<T>* left = cur->prev[level];
      Node<T>* right = cur->next[level];
      left->next[level] = right;
      right->prev[level] = left;
    }
    alloc.destroy(cur);
    alloc.deallocate(cur, 1);
  }
};


vector<int> a;

void check(int l, int r) {
  reverse(a.begin() + l, a.begin() + r);
  for (int i = 1; i < a.size(); i++)
    if (a[i] < a[i - 1]) {
      reverse(a.begin() + l, a.begin() + r);
      return;
    }
  cout << "yes\n";
  cout << l + 1 << " " << r;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  data_structures::SkipList<int> v;
  v.insert(0);
  v.insert(1);
  v.insert(n - 1);
  v.insert(n);
  for (int i = 2; i < n; i++) {
    int s1 = a[i - 2] < a[i - 1] ? 1 : 0;
    int s2 = a[i - 1] < a[i] ? 1 : 0;
    if (s1 != s2) {
      v.insert(i);
      v.insert(i - 1);
    }
  }
  if (v.size() >= 15) {
    cout << "no";
    return 0;
  }
  for (int l : v)
    for (int r : v)
      if (l < r)
        check(l, r);
  cout << "no";

  return 0;
}