#include <stdio.h>
#include <assert.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>


/*
 *
 * GitHub link:
 * https://github.com/MrKaStep/TimSort/tree/dev/timSort/timSort
 *
 */


typedef unsigned int ui32;

template<class BidirIt>
void selectionSort(BidirIt first, BidirIt last);
template<class BidirIt, class Compare>
void selectionSort(BidirIt first, BidirIt last, Compare comp);

template<class BidirIt>
void insertionSort(BidirIt first, BidirIt last);
template<class BidirIt, class Compare>
void insertionSort(BidirIt first, BidirIt last, Compare comp);

template<class FwdIt>
void merge(FwdIt first, FwdIt middle, FwdIt last,
           FwdIt buffer);
template<class FwdIt, class Compare>
void merge(FwdIt first, FwdIt middle, FwdIt last,
           FwdIt buffer, Compare comp);

template<class FwdIt>
void swapSegments(FwdIt a, FwdIt b, ui32 length);

template<class RandIt>
void sortSegments(RandIt first, RandIt last, ui32 length);
template<class RandIt, class Compare>
void sortSegments(RandIt first, RandIt last, ui32 length,
                  Compare comp);

template<class RandIt>
void reorderSegments(RandIt first, RandIt middle, RandIt last, ui32 length);
template<class RandIt, class Compare>
void reorderSegments(RandIt first, RandIt middle, RandIt last, ui32 length,
                     Compare comp);

template<class RandIt>
void inplaceMerge(RandIt first, RandIt middle, RandIt last);
template<class RandIt, class Compare>
void inplaceMerge(RandIt first, RandIt middle, RandIt last,
                  Compare comp);

/*
 * Implementation
 */


template<class BidirIt>
void selectionSort(BidirIt first, BidirIt last) {
    selectionSort(first, last,
                  std::less<typename std::iterator_traits<BidirIt>::value_type>());
}
template<class BidirIt, class Compare>
void selectionSort(BidirIt first, BidirIt last, Compare comp) {
    for (; first != last; ++first) {
        BidirIt minimum = first;
        for (BidirIt it = first; it != last; ++it)
            if (comp(*it, *minimum))
                minimum = it;
        std::iter_swap(minimum, first);
    }
}

template<class BidirIt>
void insertionSort(BidirIt first, BidirIt last) {
    insertionSort(first, last,
                  std::less<typename std::iterator_traits<BidirIt>::value_type>());
}
template<class BidirIt, class Compare>
void insertionSort(BidirIt first, BidirIt last, Compare comp) {
    typedef typename std::iterator_traits<BidirIt>::value_type valueType;
    for (BidirIt toPush = std::next(first); toPush != last; ++toPush) {
        valueType val = *toPush;
        BidirIt cur = toPush;
        while (cur != first && comp(val, *std::prev(cur))) {
            *cur = *std::prev(cur);
            --cur;
        }
        *cur = val;
    }
}

template<class FwdIt>
void merge(FwdIt first, FwdIt middle, FwdIt last,
           FwdIt buffer) {
    merge(first, middle, last,
          std::less<typename std::iterator_traits<FwdIt>::value_type>());
}
template<class FwdIt, class Compare>
void merge(FwdIt first, FwdIt middle, FwdIt last,
           FwdIt buffer, Compare comp) {
    FwdIt left = first;
    for (FwdIt ptrBuff = buffer; left != middle; ++left, ++ptrBuff)
        std::iter_swap(left, ptrBuff);
    left = buffer;
    FwdIt right = middle;
    FwdIt write = first;
    FwdIt buffLast = buffer + (middle - first);
    while (write != last && left != buffLast && right != last)
        std::iter_swap(write++,
                       comp(*left, *right) ? left++ : right++);
    while (left != buffLast)
        std::iter_swap(write++, left++);
    while (right != last)
        std::iter_swap(write++, right++);
}

template<class FwdIt>
void swapSegments(FwdIt a, FwdIt b, ui32 length) {
    if (a == b)
        return;
    for (ui32 i = 0; i < length; ++i) {
        std::iter_swap(a++, b++);
    }
}

template<class RandIt>
void sortSegments(RandIt first, RandIt last, ui32 length) {
    sortSegments(first, last, length,
                 std::less<typename std::iterator_traits<RandIt>::value_type>());
}
template<class RandIt, class Compare>
void sortSegments(RandIt first, RandIt last, ui32 length, Compare comp) {
    for (; first != last; first += length) {
        RandIt minimum = first;
        for (RandIt it = first; it != last; it += length)
            if (comp(*it, *minimum) || *it == *minimum &&
                comp(it[length - 1], minimum[length - 1]))
                minimum = it;
        swapSegments(minimum, first, length);
    }
}

template<class RandIt>
void reorderSegments(RandIt first, RandIt middle, RandIt last, ui32 length) {
    reorderSegments(first, middle, last, length,
                    std::less<typename std::iterator_traits<RandIt>::value_type>());
}
template<class RandIt, class Compare>
void reorderSegments(RandIt first, RandIt middle, RandIt last, ui32 length,
                     Compare comp) {
    ui32 segmentsCount = (last - first) / length;
    if (std::distance(first, middle) > static_cast<int>(length * segmentsCount))
        return;
    RandIt middleSegmentBegin = first + length * ((middle - first) / length);
    RandIt lastSegmentBegin = first + length * (segmentsCount - 1);
    swapSegments(middleSegmentBegin, lastSegmentBegin, length);
    sortSegments(first, lastSegmentBegin, length, comp);
}

template<class RandIt>
void inplaceMerge(RandIt first, RandIt middle, RandIt last) {
    inplaceMerge(first, middle, last,
                 std::less<typename std::iterator_traits<RandIt>::value_type>());
}
template<class RandIt, class Compare>
void inplaceMerge(RandIt first, RandIt middle, RandIt last, Compare comp) {
    if (last - first < 17) {
        selectionSort(first, last, comp);
        return;
    }
    ui32 totalLength = last - first;
    ui32 leftLength = middle - first;
    ui32 rightLength = last - middle;
    ui32 segmentLength = 0;
    while ((segmentLength + 1) * (segmentLength + 1) <= totalLength)
        ++segmentLength;
    ui32 segmentsCount = totalLength / segmentLength;

    if (std::distance(first, middle) < static_cast<int>(segmentLength * segmentsCount)) {
        reorderSegments(first, middle, last, segmentLength, comp);
        RandIt lastSegmentBegin = first + segmentLength * (segmentsCount - 1);
        for (ui32 i = 0; i + 2 < segmentsCount; ++i)
            merge(first + segmentLength * i,
                  first + segmentLength * (i + 1),
                  first + segmentLength * (i + 2),
                  lastSegmentBegin,
                  comp);

    }
    ui32 badSegmentLength = segmentLength + totalLength % segmentLength;
    RandIt badSegmentBegin = last - badSegmentLength;
    selectionSort(last - 2 * badSegmentLength, last, comp);
    RandIt toMerge = badSegmentBegin;
    while (toMerge != first) {
        RandIt mergeFirst = first + badSegmentLength <= toMerge ?
            toMerge - badSegmentLength : first;
        merge(mergeFirst,
              toMerge,
              toMerge + badSegmentLength,
              badSegmentBegin,
              comp);
        toMerge = mergeFirst;
    }
    selectionSort(badSegmentBegin, last);
    return;
}


template<class RandIt, class Compare>
class RunsStack {
private:
    Compare comp;
    std::vector<std::pair<RandIt, ui32> > runs;
    RandIt last;

public:
    RunsStack(Compare _comp);

    void addRun(RandIt first, ui32 length);
    void mergeXY();
    void mergeYZ();

    size_t size() const;
    ui32 lenX() const;
    ui32 lenY() const;
    ui32 lenZ() const;
};

template<class RandIt, class Compare>
RunsStack<RandIt, Compare>::RunsStack(Compare _comp) :
    comp(_comp),
    runs(),
    last() {}
template<class RandIt, class Compare>
void RunsStack<RandIt, Compare>::addRun(RandIt first, ui32 length) {
    runs.emplace_back(first, length);
    last = first + length;
}
template<class RandIt, class Compare>
void RunsStack<RandIt, Compare>::mergeXY() {
    assert(runs.size() > 1);
    inplaceMerge(runs[runs.size() - 2].first,
                 runs[runs.size() - 1].first,
                 last,
                 comp);
    runs[runs.size() - 2].second += runs[runs.size() - 1].second;
    runs.pop_back();
}
template<class RandIt, class Compare>
void RunsStack<RandIt, Compare>::mergeYZ() {
    assert(runs.size() > 2);
    inplaceMerge(runs[runs.size() - 3].first,
                 runs[runs.size() - 2].first,
                 runs[runs.size() - 1].first,
                 comp);
    runs[runs.size() - 3].second += runs[runs.size() - 2].second;
    runs.erase(runs.end() - 2, runs.end() - 1);
}
template<class RandIt, class Compare>
size_t RunsStack<RandIt, Compare>::size() const {
    return runs.size();
}
template<class RandIt, class Compare>
ui32 RunsStack<RandIt, Compare>::lenX() const {
    assert(runs.size() > 0);
    return (runs.end() - 1)->second;
}
template<class RandIt, class Compare>
ui32 RunsStack<RandIt, Compare>::lenY() const {
    assert(runs.size() > 1);
    return (runs.end() - 2)->second;
}
template<class RandIt, class Compare>
ui32 RunsStack<RandIt, Compare>::lenZ() const {
    assert(runs.size() > 2);
    return (runs.end() - 3)->second;
}




enum EWhatMerge {
    WM_NoMerge,
    WM_MergeXY,
    WM_MergeYZ
};

class ITimSortParams {
public:
    virtual ui32 minRun(ui32 n) const = 0;
    virtual bool needMerge(ui32 lenX, ui32 lenY) const = 0;
    virtual EWhatMerge whatMerge(ui32 lenX, ui32 lenY, ui32 lenZ) const = 0;
    virtual ui32 getGallop() const = 0;
};

class defaultTimSortParams : public ITimSortParams {
public:
    ui32 minRun(ui32 n) const {
        ui32 flag = 0;
        while (n >= 64)
            flag |= n & 1, n >>= 1;
        return n + flag;
    }
    bool needMerge(ui32 lenX, ui32 lenY) const {
        return lenY <= lenX;
    }
    EWhatMerge whatMerge(ui32 lenX, ui32 lenY, ui32 lenZ) const {
        if (lenZ <= lenX + lenY)
            return lenX <= lenZ ? WM_MergeXY : WM_MergeYZ;
        return lenY <= lenX ? WM_MergeXY : WM_NoMerge;
    }
    ui32 getGallop() const {
        return 0;
    }
};

static const defaultTimSortParams DEFAULT;

template<class RandIt>
void timSort(RandIt first, RandIt last,
             const ITimSortParams& params = DEFAULT);
template<class RandIt, class Compare>
void timSort(RandIt first, RandIt last, Compare comp,
             const ITimSortParams& params = DEFAULT);

template<class RandIt>
void timSort(RandIt first, RandIt last,
             const ITimSortParams& params) {
    timSort(first, last,
            std::less<typename std::iterator_traits<RandIt>::value_type>(),
            params);
}

template<class RandIt, class Compare>
bool isSorted(RandIt first, RandIt second, RandIt third, Compare comp) {
    return !(comp(*first, *second) && comp(*third, *second) ||
             comp(*second, *first) && comp(*second, *third));
}

int N = 100000;
std::vector<int> v(N);

template<class RandIt, class Compare>
void timSort(RandIt first, RandIt last, Compare comp,
             const ITimSortParams& params) {

    ui32 minrun = params.minRun(last - first);

    RunsStack<RandIt, Compare> runsStack(comp);
    for (RandIt current = first; current != last;) {
        if (current + 1 == last) {
            runsStack.addRun(current, 1);
            break;
        }
        RandIt runEnd = current + 2;
        while (runEnd != last &&
               (std::distance(current, runEnd) < static_cast<int>(minrun) ||
                isSorted(runEnd - 2, runEnd - 1, runEnd, comp))) {
            ++runEnd;
        }
        ui32 runLength = runEnd - current;
        if (comp(*std::prev(runEnd), *current))
            for (ui32 i = 0; i < runLength / 2; ++i)
                std::iter_swap(current + i, runEnd - i - 1);
        insertionSort(current, runEnd, comp);
        runsStack.addRun(current, runLength);
        current = runEnd;
        while (runsStack.size() > 2) {
            bool stop = false;
            switch (params.whatMerge(runsStack.lenX(),
                                     runsStack.lenY(),
                                     runsStack.lenZ())) {
            case WM_MergeXY:
                runsStack.mergeXY();
                break;
            case WM_MergeYZ:
                runsStack.mergeYZ();
                break;
            case WM_NoMerge:
                stop = true;
                break;
            }
            if (stop)
                break;
        }
        if (runsStack.size() == 2 && params.needMerge(runsStack.lenX(),
                                                      runsStack.lenY()))
            runsStack.mergeXY();
    }
    while (runsStack.size() > 1)
        runsStack.mergeXY();
}

#pragma warning(disable:4996)

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

const int mod=1e9+7;

struct eve{
    int a,b,k,pos;
};

bool operator<(eve a, eve e) {
    if (a.a != e.a) return a.a < e.a;
    if (a.k != e.k) return a.k < e.k;
    return a.b < e.b;
}

bool operator==(eve a, eve b) {
    return !(a < b || b < a);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    eve one;
    std::vector<eve> v;
    std::vector<std::pair<int, int>> ans;
    std::map<int, std::map<int, int>> t;
    std::map<int, std::map<int, int>>::iterator it;
    std::map<int, int>::iterator itr;
    int n, m, i, a, b, c;
    scanf("%d", &n);
    For(i, n) {
        scanf("%d%d", &a, &b);
        one.a = a;
        one.b = b;
        one.k = mod;
        one.pos = i;
        v.pb(one);
    }
    scanf("%d", &m);
    For(i, m) {
        scanf("%d%d%d", &a, &b, &c);
        one.a = a;
        one.b = b;
        one.k = c;
        one.pos = i + n;
        v.pb(one);
    }
    timSort(v.begin(), v.end(), operator<);
    For(i, n + m) {
        if (v[i].k == mod) {
            it = t.upper_bound(v[i].b - 1);
            if (it == t.end()) {
                printf("NO");
                return 0;
            }
            itr = it->second.begin();
            itr->second--;
            ans.pb(std::make_pair(v[i].pos, itr->first));
            if (itr->second == 0) {
                it->second.erase(itr);
            }
            if (it->second.size() == 0) t.erase(it);
        } else {
            t[v[i].b][v[i].pos] = v[i].k;
        }
    }
    printf("YES\n");
    timSort(ans.begin(), ans.end());
    For(i, n) {
        printf("%d ", ans[i].second - n + 1);
    }
}