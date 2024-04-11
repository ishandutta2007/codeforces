#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
#define ll long long
const int N = 3e5 + 100;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <string> s(n);
        vector <vector <vector <int > > > indexes(60, vector <vector <int> > (n));
        for(int i = 0; i < n; i++){
            cin >> s[i];
            for(int j = 0; j < sz(s[i]); j++){
                if(s[i][j] >= 'a' && s[i][j] <= 'z'){
                    indexes[s[i][j] - 'a'][i].push_back(j);
                }
                else{
                    indexes[s[i][j] - 'A' + 30][i].push_back(j);
                }
            }
        }
        vector <pair <int, int> > order;
        vector <int> cnt(60);
        for(int i = 0; i < sz(s[0]); i++){
            int second = 0;
            int first =0 ;
            if(s[0][i] >= 'a' && s[0][i] <= 'z'){
                second = cnt[s[0][i] - 'a'];
                cnt[s[0][i] - 'a']++;
                first = s[0][i] - 'a';
            }
            else{
                first = s[0][i] - 'A' + 30;
                second = cnt[s[0][i] - 'A' + 30];
                cnt[s[0][i] - 'A' + 30]++;
            }
            order.push_back({first, second});
        }
        vector <vector <int> > dp(60, vector <int> (1 << n, 0));
        vector <vector <pair <int, int> > > pr(60, vector <pair <int, int> > (1 << n, {-1, -1}));
        pair <int, int> st = {-1, -1};
        for(auto v : order){
            int j = v.X;
     //       cout << "sym" << j << " " << v.Y <<"\n";
            bool fl = 1;
            for(int k = 0; k < n; k++){
                if(!sz(indexes[j][k])){
                    fl = 0;
                }
            }
            if(!fl){
                continue;
            }
            for(int msk = 0; msk < (1 << n); msk++){
                if((msk & 1) != v.Y){
                    continue;
                }
                bool flag = 1;
                for(int idx = 0; idx < n; idx++){
                    if(sz(indexes[j][idx]) == 0 || ((1 << idx) & msk) != 0 && sz(indexes[j][idx]) == 1){
                        flag = 0;
                    }
                }
                if(!flag){
                    continue;
                }
       //         cout << msk << "\n";
                dp[j][msk] = 1;
                for(int idx = 0; idx < n; idx++){
                    if((1 << idx) & msk){
                        if(dp[j][msk ^ (1 << idx)] > dp[j][msk]){
                            dp[j][msk] = dp[j][msk ^ (1 << idx)];
                            pr[j][msk] = pr[j][msk ^ (1 << idx)];
                        }
                    }
                }
                for(int from = 0; from < 60; from++){
                    bool fl = 1;
                    int msk_from = 0;
                    for(int idx = 0; idx < n; idx++){
                        if(sz(indexes[from][idx]) == 0){
                            fl = 0;
                            break;
                        }
                        if(indexes[from][idx][0] >= indexes[j][idx][(msk >> idx) & 1]){
                            fl = 0;
                            break;
                        }
                        if(sz(indexes[from][idx]) == 2 && indexes[from][idx][1] < indexes[j][idx][(msk >> idx) & 1]){
                            msk_from |= (1 << idx);
                        }
                    }
                    if(!fl){
                        continue;
                    }
              //      cout << "from "  << from << " " << msk_from << "\n";
                    if(dp[from][msk_from] + 1 > dp[j][msk]){
                        dp[j][msk] = dp[from][msk_from] + 1;
                        pr[j][msk] = {from, msk_from};
                    }
                }
                if(st.X == -1 && dp[j][msk] != 0 || dp[j][msk] > dp[st.X][st.Y]){
                    st = {j, msk};
                }
            }
        }
        //cout << st.X << " " << st.Y << "\n";
        if(st.X == -1){
            cout << 0 << "\n";
            cout << "\n";
            continue;
        }
        cout << dp[st.X][st.Y] << "\n";
        
        string res = "";
        while(st.X != -1){
            if(st.X >= 30){
                char c = (st.X - 30) + 'A';
                res += c;
            }
            else{
                char c = st.X + 'a';
                res += c;
            }
            pair <int, int> p = pr[st.X][st.Y];
            st.X = p.X;
            st.Y = p.Y;
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
    return 0;
}