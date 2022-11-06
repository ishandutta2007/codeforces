#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
#define rem_dupl(x) sort(all(x)); x.erase(unique(all(x)), x.end())
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> ii;
#define x first
#define y second

//mt19937 rand32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rand64(chrono::steady_clock::now().time_since_epoch().count());

const db eps = 1e-9;
const int maxn = (int)2e5 + 5;
const ll mod = (int)1e9 + 7; // 998244353

vector<char> aux;
vector<int> cnt(1000);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    for(char c:s){
        cnt[c]++;
        aux.push_back(c);
    }
    rem_dupl(aux);

    for(int t = 1; t < n; t++){
        if(n % t)
            continue;

        vector<int>cnt2 = cnt;

        string rr = "";
        rr.assign(n/t, '?');
        vector<string>s(t, rr);

        bool good = 1;

        if(n/t > 1){
            
            for(int i = 0; i < t and good; i++){
            
                for(int j = 0; n/t - j - 1 > j and good; j++){
                    bool f = 0;
                    for(char c:aux)
                        if(cnt[c] >= 2){
                            s[i][j] = s[i][n/t - j - 1] = c;
                            cnt[c]-=2;
                            f = 1;
                            break;
                        }
                    if(!f)
                        good = 0;
                }

            }

        }

        if( (n/t) & 1){
            for(int i = 0; i < t and good; i++){
                bool f = 0;
                for(char c:aux)
                    if(cnt[c] > 0){
                        cnt[c]--;
                        s[i][(n/t)>>1] = c; 
                        f = 1;
                        break;
                    }
                if(!f)
                    good = 0;
            }
        }
            

        if(good){
            cout << t << endl;
            for(int i = 0; i < t; i++)
                cout << s[i] << ' ';
            return 0;
        } 

        cnt = cnt2;
    }

    cout << n << endl;

    for(char c:s)
        cout << c << ' ';
    
    return 0;
}