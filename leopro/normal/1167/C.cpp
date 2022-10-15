#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include <cmath>

using namespace std;

typedef long long ll;

namespace useful {
    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) { os << t << " "; }
        os << "\n";
        return os;
    }

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }

    template<typename T>
    void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }

}

using namespace useful;

struct Group {
    vector<int> people;
    int component;

    Group() : people(0), component(0) {}
};

struct Person {
    vector<int> groups;
    int component;

    Person() : groups(0), component(0) {}
};

void dfs(int c, Person *p, vector<Person> &people, vector<Group> &groups);

void dfs(int c, Group *g, vector<Person> &people, vector<Group> &groups) {
    if (g->component != 0) return;
    g->component = c;
    for (int p : g->people) {
        dfs(c, &people[p], people, groups);
    }
}

void dfs(int c, Person *p, vector<Person> &people, vector<Group> &groups) {
    if (p->component != 0) return;
    p->component = c;
    for (int g : p->groups) {
        dfs(c, &groups[g], people, groups);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Person> people(n);
    vector<Group> groups(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        groups[i].people = vector<int>(k);
        cin >> groups[i].people;
        for (int j = 0; j < k; ++j) {
            groups[i].people[j]--;
        }
        for (int p : groups[i].people) {
            people[p].groups.push_back(i);
        }
    }
    int c = 1;
    for (int i = 0; i < n; ++i) {
        if (people[i].component == 0) dfs(c++, &people[i], people, groups);
    }
    vector<int> count(c);
    for (int i = 0; i < n; ++i) {
        count[people[i].component]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << count[people[i].component] << " ";
    }
    cout << endl;
}