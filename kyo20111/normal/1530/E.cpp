#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

void solve(){
    cin >> s;
    int n = s.size();

    vector<int> cnt(26);
    for(auto x : s) cnt[x-'a']++;

    int mx = *max_element(cnt.begin(), cnt.end());

    if(mx == n){
        cout << s;
        return;
    }

    int s = -1;
    for(int i=25;i>=0;i--) if(cnt[i] == 1) s = i;

    if(s != -1){
        cout << char(s + 'a'), cnt[s]--;
        for(int i=0;i<26;i++) while(cnt[i]) cout << char(i + 'a'), cnt[i]--;
        return;
    }

    s = 0;
    while(!cnt[s]) s++;
    cout << char(s + 'a'), cnt[s]--;

    if(mx > (n+2)/2){

        if(cnt[s]+1 == mx){
            int x = s+1;
            while(!cnt[x]) x++; // cnt[x] > 1
            cout << char(x + 'a'), cnt[x]--; 

            int y = x+1;
            while(y<26 && !cnt[y]) y++;

            if(y > 25){
                while(cnt[x]) cout << char(x + 'a'), cnt[x]--;
                while(cnt[s]) cout << char(s + 'a'), cnt[s]--;
            }else{
                while(cnt[s]) cout << char(s + 'a'), cnt[s]--;
                cout << char(y + 'a'), cnt[y]--;
                while(cnt[x]) cout << char(x + 'a'), cnt[x]--;
                while(cnt[y]) cout << char(y + 'a'), cnt[y]--;
                for(int i=y+1;i<26;i++) while(cnt[i]) cout << char(i + 'a'), cnt[i]--;
            }
        }else{
            int big = 0;
            for(int i=s+1;i<26;i++) big += cnt[i];

            if(big >= cnt[s]+1){ // s      .
                for(int i=0;i<s;i++) while(cnt[i]) cout << char(i + 'a'), cnt[i]--;
                for(int i=s+1;i<26;i++) while(cnt[i]){
                    if(cnt[s]) cout << char(s + 'a'), cnt[s]--;
                    cout << char(i + 'a'), cnt[i]--;
                }
                if(cnt[s]) cout << char(s + 'a'), cnt[s]--;
            }else{ // s     
                int need = min(big+1, cnt[s]); //    
                cnt[s] -= need;

                string t;
                for(int i=s-1;i>=0;i--) while(cnt[i]){
                    t += char(i + 'a'), cnt[i]--;
                    if(cnt[s]) t += char(s + 'a'), cnt[s]--;
                }
                reverse(t.begin(), t.end());
                cout << t;

                for(int i=s+1;i<26;i++) while(cnt[i]){
                    if(need) cout << char(s + 'a'), need--;
                    cout << char(i + 'a'), cnt[i]--;
                }
                if(need) cout << char(s + 'a'), need--;
            }
        }
    }else{ // s   .
        for(int i=s+1;i<26;i++) while(cnt[i]){
            if(cnt[s]) cout << char(s + 'a'), cnt[s]--;
            cout << char(i + 'a'), cnt[i]--;
        }
        if(cnt[s]) cout << char(s + 'a'), cnt[s]--;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}