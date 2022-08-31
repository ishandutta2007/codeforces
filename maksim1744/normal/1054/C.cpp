/*
    18.10.2018 19:46:23
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

vector< pair< pair< int, int >, int > > ans;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > l(n), r(n);
    for (auto& item : l) {
        cin >> item;
    }
    for (auto& item : r) {
        cin >> item;
    }
    if (l[0] != 0 || r.back() != 0) {
        cout << "NO\n";
        return 0;
    }
    vector< vector< int > > al;
    al.push_back(vector< int >(1, 0));
    for (int i = 1; i < n; ++i) {
        int k = l[i];
        if (k > i) {
            cout << "NO\n";
            return 0;
        }
        int j = al.size() - 1;
        int s = 0;
        while (j >= 0 && s < k) {
            s += al[j].size();
            --j;
        }
        // cout << i << ' ' << s << ' ' << k << endl;
        // cout << "al = {\n";
        // for (auto item : al) {
        //     for (auto elem : item) {
        //         cout << elem << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "}\n\n";
        if (s == k) {
            if (j == -1) {
                ++j;
                al.insert(al.begin(), vector< int >());
            }
            al[j].push_back(i);
        } else {
            vector< int > v1, v2;
            ++j;
            for (int i = 0; i < (s - k); ++i) {
                v1.push_back(al[j][i]);
            }
            for (int i = 0; i < al[j].size() - (s - k); ++i) {
                v2.push_back(al[j][i + (s - k)]);
            }
            v1.push_back(i);
            al.erase(al.begin() + j);
            al.insert(al.begin() + j, v2);
            al.insert(al.begin() + j, v1);
        }
    }
    // cout << "al = {\n";
    // for (auto item : al) {
    //     for (auto elem : item) {
    //         cout << elem << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "}\n";
    reverse(r.begin(), r.end());
    vector< vector< int > > ar;
    ar.push_back(vector< int >(1, 0));
    for (int i = 1; i < n; ++i) {
        int k = r[i];
        if (k > i) {
            cout << "NO\n";
            return 0;
        }
        int j = ar.size() - 1;
        int s = 0;
        while (j >= 0 && s < k) {
            s += ar[j].size();
            --j;
        }
        // cout << i << ' ' << s << ' ' << k << endl;
        // cout << "ar = {\n";
        // for (auto item : ar) {
        //     for (auto elem : item) {
        //         cout << elem << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "}\n\n";
        if (s == k) {
            if (j == -1) {
                ++j;
                ar.insert(ar.begin(), vector< int >());
            }
            ar[j].push_back(i);
        } else {
            vector< int > v1, v2;
            ++j;
            for (int i = 0; i < (s - k); ++i) {
                v1.push_back(ar[j][i]);
            }
            for (int i = 0; i < ar[j].size() - (s - k); ++i) {
                v2.push_back(ar[j][i + (s - k)]);
            }
            v1.push_back(i);
            ar.erase(ar.begin() + j);
            ar.insert(ar.begin() + j, v2);
            ar.insert(ar.begin() + j, v1);
        }
    }
    // reverse(ar.begin(), ar.end());
    for (int i = 0; i < ar.size(); ++i) {
        for (int j = 0; j < ar[i].size(); ++j) {
            ar[i][j] = n - 1 - ar[i][j];
        }
        // reverse(ar[i].begin(), ar[i].end());
    }
    // cout << "ar = {\n";
    // for (auto item : ar) {
    //     for (auto elem : item) {
    //         cout << elem << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "}\n";
    vector< int > v1, v2;
    for (int i = 0; i < al.size(); ++i) {
        for (int j = 0; j < al[i].size(); ++j) {
            v1.push_back(al[i][j]);
        }
        v1.push_back(-1);
    }
    for (int i = 0; i < ar.size(); ++i) {
        for (int j = 0; j < ar[i].size(); ++j) {
            v2.push_back(ar[i][j]);
        }
        v2.push_back(-1);
    }
    // for (auto item : v1) {
    //     cout << item << ' ';
    // }
    // cout << '\n';
    // for (auto item : v2) {
    //     cout << item << ' ';
    // }
    // cout << '\n';
    int il1 = 0, il2 = 1, ir1 = 0, ir2 = 1;
    vector< int > pt(n);
    int p = 1;
    while (al.size() > 0) {
        // cout << "al = ";
        // for (auto item : al) {
        //     for (auto elem : item) {
        //         cout << elem << ' ';
        //     }
        //     cout << " | ";
        // }
        // cout << '\n';
        // cout << "ar = ";
        // for (auto item : ar) {
        //     for (auto elem : item) {
        //         cout << elem << ' ';
        //     }
        //     cout << " | ";
        // }
        // cout << '\n';
        vector< int > tmpl(ar[0].begin(), ar[0].begin() + min(al[0].size(), ar[0].size()));
        vector< int > tmpr(al[0].begin(), al[0].begin() + min(al[0].size(), ar[0].size()));
        reverse(tmpl.begin(), tmpl.end());
        if (tmpl == tmpr) {
            for (auto item : tmpl) {
                pt[item] = p;
            }
            ++p;
            int mn = min(al[0].size(), ar[0].size());
            for (int i = 0; i < mn; ++i) {
                al[0].erase(al[0].begin());
                ar[0].erase(ar[0].begin());
            }
            if (al[0].size() == 0) {
                al.erase(al.begin());
            }
            if (ar[0].size() == 0) {
                ar.erase(ar.begin());
            }
        } else {
            if (al[0][0] == ar[0][0]) {
                pt[al[0][0]] = p;
                ++p;
                al[0].erase(al[0].begin());
                ar[0].erase(ar[0].begin());
                if (al[0].size() == 0) {
                    al.erase(al.begin());
                }
                if (ar[0].size() == 0) {
                    ar.erase(ar.begin());
                }
            } else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (auto item : pt) {
        cout << item << ' ';
    }
    cout << '\n';
    // cout << "ar = {\n";
    // for (auto item : ar) {
    //     for (auto elem : item) {
    //         cout << elem << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "}\n";
    // return 0;
    /*
    vector< int > val1(n);
    for (int i = 0; i < al.size(); ++i) {
        for (int j = 0; j < al[i].size(); ++j) {
            val1[al[i][j]] = i;
        }
    }
    vector< int > val2(n);
    for (int i = 0; i < ar.size(); ++i) {
        for (int j = 0; j < ar[i].size(); ++j) {
            val2[ar[i][j]] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans.push_back({{val1[i], val2[i]}, i});
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n - 1; ++i) {
        if (ans[i].first.second > ans[i + 1].first.second) {
            cout << "NO\n";
            return 0;
        }
    }
    vector< int > pt(n);
    int p = 1;
    pt[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (ans[i].first != ans[i - 1].first) {
            ++p;
        }
        pt[i] = p;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << pt[i] << ' ';
    }
    cout << '\n';*/
    return 0;
}