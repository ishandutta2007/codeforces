#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int n;
string s;
int freq[Maxl];

bool Check(const string &s)
{
    for (int i = 0; i + 1 < s.length(); i++)
        if (s[i] + 1 == s[i + 1] || s[i] - 1 == s[i + 1])
            return false;
    return true;
}

int main()
{
    cin >> n;
    while (n--) {
        cin >> s;
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        vector <int> seq;
        for (int i = 0; i < Maxl; i++) if (freq[i] > 0)
            seq.push_back(i);
        if (seq.size() == 1) printf("%s\n", string(s.length(), 'a' + seq.back()).c_str());
        else if (seq.size() == 2) {
            string res = string(freq[seq[0]], seq[0] + 'a') + string(freq[seq[1]], seq[1] + 'a');
            if (Check(res)) cout << res << endl;
            else cout << "No answer" << endl;
        } else if (seq.size() == 3) {
            string res = string(freq[seq[0]], seq[0] + 'a') + string(freq[seq[2]], seq[2] + 'a')
                         + string(freq[seq[1]], seq[1] + 'a');
            if (Check(res)) cout << res << endl;
            else {
                res = string(freq[seq[1]], seq[1] + 'a') + string(freq[seq[0]], seq[0] + 'a')
                      + string(freq[seq[2]], seq[2] + 'a');
                if (Check(res)) cout << res << endl;
                else cout << "No answer" << endl;
            }
        } else {
            string res;
            for (int i = 1; i < seq.size(); i += 2)
                while (freq[seq[i]]--) res += string(1, seq[i] + 'a');
            for (int i = 0; i < seq.size(); i += 2)
                while (freq[seq[i]]--) res += string(1, seq[i] + 'a');
            cout << res << endl;
        }
    }
    return 0;
}