#include <iostream>
#include <string> 
#include <set>
#include <vector>
using namespace std;

int main() {
    string s;         
             
    cin >> s;
    
    int k, ans = 0;
    
    cin >> k;
    
    vector<int> cnt(256, 0);
    vector<bool> erased(256, false);
    
    for(int i = 0; i < s.length(); ++i)
            cnt[s[i]]++;
    
    while(k > 0) {
            int j = 'a';
            for(int i = 'a';  i <= 'z'; ++i) 
                        if(cnt[i] <= cnt[j] && !erased[i] && cnt[i] > 0 || (erased[j] && cnt[i] > 0 && !erased[i]))
                                  j = i;
            if(erased[j])
                         break;
            k -= cnt[j];
            if(k < 0)
                 break;
            erased[j] = true;
    }
    
    for(int i = 'a'; i <= 'z'; ++i)
            if(cnt[i] > 0 && !erased[i])
                      ++ans;
    
    cout << ans << endl;
    
    for(int i = 0; i < s.length(); ++i)
            if(!erased[s[i]])
                             cout << s[i];
    cout << endl;             
    
    cin >> k;
    
    return 0;                           
}