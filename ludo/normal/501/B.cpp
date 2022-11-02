#include <iostream>
// #include <cstdio>
#include <string>
#include <set>

using namespace std;

struct user {
    string old, cur;
};

bool operator<(const user &a, const user &b)
{
    return a.cur < b.cur;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int q;
    cin >> q;

    set<user> users;
    user u, s;
    for (int i = 0; i < q; i++) {
        cin >> u.old >> u.cur;
        s.cur = u.old;
        set<user>::iterator ptr = users.find(s);
        if (ptr != users.end()) {
            u.old = ptr->old;
            users.erase(ptr);
        }
        users.insert(u);
    }
    cout << users.size() << endl;
    for (set<user>::iterator it = users.begin(); it != users.end(); ++it) {
        cout << it->old << " " << it->cur << endl;
    }
    return 0;
}