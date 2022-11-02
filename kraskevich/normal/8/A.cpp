#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t1, t2, rev;
    
    cin >> s >> t1 >> t2;
    
    rev = s;
    int n = s.length();
    for(int i = 0; i < n; ++i)
            rev[i] = s[n - i - 1];
    
    long long p_pow[n];
    p_pow[0]= 1;
    for(int i = 1; i < n; ++i)
            p_pow[i] = p_pow[i - 1] * 31;
    
    long long h[n], revh[n];
    for(int i = 0; i < n; ++i) {
            h[i] = p_pow[i] * (s[i] - 'a' + 1);
            revh[i] = p_pow[i] * (rev[i] - 'a' + 1);
            if(i) {
                  h[i] += h[i - 1];
                  revh[i] += revh[i - 1];
            }
    }
    
    long long hash1 = 0;
    for(int i = 0; i < t1.length(); ++i) 
            hash1 += p_pow[i] * (t1[i] - 'a' + 1);
    long long hash2 = 0;
    for(int i = 0; i < t2.length(); ++i)
            hash2 += p_pow[i] * (t2[i] - 'a' + 1);
    
    bool front = false;
    int pos1 = -1, pos2 = -1;
    for(int l = 0, r = t1.length() - 1; r < n; ++l, ++r) 
            if(hash1 * p_pow[l] == (h[r] - (l == 0 ? 0 : h[l - 1]))) {
                     pos1 = l;
                     break;
            }
     for(int l = pos1 + t1.length(), r = t2.length() - 1 + l; r < n; ++l, ++r) 
            if(hash2 * p_pow[l] == (h[r] - (l == 0 ? 0 : h[l - 1]))) 
                     pos2 = l;
     if(pos1 >= 0 && pos2 > 0 && t1.length() < n && t2.length() < n)
             front = true;
             
    bool back = false;
    pos1 = -1, pos2 = -1;
    for(int l = 0, r = t1.length() - 1; r < n; ++l, ++r) 
            if(hash1 * p_pow[l] == (revh[r] - (l == 0 ? 0 : revh[l - 1]))) {
                     pos1 = l;
                     break;
            }
     for(int l = pos1 + t1.length(), r = t2.length() - 1 + l; r < n; ++l, ++r) 
            if(hash2 * p_pow[l] == (revh[r] - (l == 0 ? 0 : revh[l - 1]))) 
                     pos2 = l;
     if(pos1 >= 0 && pos2 > 0 && t1.length() < n && t2.length() < n)
             back = true;
             
     if(back && front) 
             cout << "both";
     if(front && !back)
              cout << "forward";
     if(back && !front)
             cout << "backward";
     if(!front && !back)
               cout << "fantasy";
     
     cin >> n;
     
     return 0;
}