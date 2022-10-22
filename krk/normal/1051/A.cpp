#include <bits/stdc++.h>
using namespace std;

int T;
string s;
vector <int> A, B, D;

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> s;
        A.clear(); B.clear(); D.clear();
        for (int i = 0; i < s.length(); i++)
            if (islower(s[i])) A.push_back(i);
            else if (isupper(s[i])) B.push_back(i);
            else D.push_back(i);
        if (A.empty()) {
            int ind;
            if (B.size() > 1) { ind = B.back(); B.pop_back(); }
            if (D.size() > 1) { ind = D.back(); D.pop_back(); }
            A.push_back(ind);
            s[ind] = 'a';
        }
        if (B.empty()) {
            int ind;
            if (A.size() > 1) { ind = A.back(); A.pop_back(); }
            if (D.size() > 1) { ind = D.back(); D.pop_back(); }
            B.push_back(ind);
            s[ind] = 'A';
        }
        if (D.empty()) {
            int ind;
            if (A.size() > 1) { ind = A.back(); A.pop_back(); }
            if (B.size() > 1) { ind = B.back(); B.pop_back(); }
            D.push_back(ind);
            s[ind] = '0';
        }
        cout << s << endl;
    }
    return 0;
}