#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
struct Person;

struct Person_ {
    int skill;
    Person *p;
    Person_ *next, *prev;

    Person_(int s) {
        skill = s;
    }
};

struct Person {
    int pos, skill;
    Person *next, *prev;

    Person(int p, int s) {
        pos = p;
        skill = s;
    }

    const bool operator<(const Person &P) const {
        return skill < P.skill;
    }

    void del(vector<Person_> &v) {
        Person_ *p = &v[pos];
        if (p->next) p->next->prev = p->prev;
        if (p->prev) p->prev->next = p->next;

        if (next && prev) {
            next->prev = prev;
            prev->next = next;
            return;
        }
        if (next) {
            next->prev = 0;
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<Person_> a(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        a[i].next = (i == n - 1) ? 0 : &a[i + 1];
        a[i].prev = (i == 0) ? 0 : &a[i - 1];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<Person> sorted(n, Person(0, 0));
    for (int i = 0; i < n; ++i) {
        sorted[i] = Person(i, a[i].skill);
    }
    sort(sorted.begin(), sorted.end());
    sorted[0].prev = 0;
    sorted[0].next = &sorted[1];
    Person head(-1, -1);
    sorted[n - 1].next = &head;
    sorted[n - 1].prev = &sorted[n - 2];
    head.prev = &sorted[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        sorted[i].next = &sorted[i + 1];
        sorted[i].prev = &sorted[i - 1];
    }
    for (int i = 0; i < n; ++i) a[sorted[i].pos].p = &sorted[i];

    vector<char> ans(n, 0);
    bool first = true;
    int free = n;
    while (free) {
        Person *programmer = head.prev;
        Person *copy = programmer;
        ans[programmer->pos] = first ? '1' : '2';
        --free;
        for (int i = 0; i < k; ++i) {
            if (programmer == 0 || a[programmer->pos].next == 0) break;
            programmer = a[programmer->pos].next->p;
            if (programmer == 0) break;
            if (programmer->pos >= n || programmer->pos < 0) break;
            ans[programmer->pos] = first ? '1' : '2';
            programmer->del(a);
            --free;
        }
        programmer = copy;
        for (int i = 0; i < k; ++i) {
            if (programmer == 0 || a[programmer->pos].prev == 0) break;
            programmer = a[programmer->pos].prev->p;
            if (programmer == 0) break;
            if (programmer->pos >= n || programmer->pos < 0) break;
            ans[programmer->pos] = first ? '1' : '2';
            programmer->del(a);
            --free;
        }
        copy->del(a);
        first = !first;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    return 0;
}