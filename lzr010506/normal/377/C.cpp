    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <algorithm>  
    using namespace std;  
    typedef long long LL;  
    const int maxn = 105;  
    const int INF = 0x3f3f3f3f;  
    int s[maxn] ,action[50] , team[50] , n , m;  
    int dp[21][1<<20] , vis[21][1<<20] ;  
      
    bool cmp(int a,int b){  
        return a > b ;  
    }  
      
    int DP(int d,int sta){  
        if(vis[d][sta]) return dp[d][sta];  
        vis[d][sta] = 1;  
        int & ans = dp[d][sta] ;  
        int max_s = 0 , p ;  
        for(int i=0;i<n;i++) if(sta & (1<<i)) {  
            max_s = s[i] , p = i;  
            break;  
        }  
        if(d == m){  
            if(action[d]==2) return ans = 0;  
            else return ans = team[d]==0 ? max_s : -max_s ;  
        }  
      
        if(sta == 0) return ans = 0;  
      
        if(team[d] == 0){  
            if(action[d] == 1) return ans = max_s + DP(d+1 , sta^(1<<p));  
            ans = -INF;  
            for(int i=0;i<n;i++) if(sta & (1<<i)) {  
                ans = max(ans , DP(d+1 , sta^(1<<i)));  
            }  
            return ans ;  
        }  
        else{  
            if(action[d] == 1) return ans = -max_s + DP(d+1 , sta^(1<<p));  
            ans = INF;  
            for(int i=0;i<n;i++) if(sta & (1<<i)) {  
                ans = min(ans , DP(d+1 , sta ^ (1<<i)));  
            }  
            return ans;  
        }  
        return 0;  
    }  
      
      
    int main()  
    {  
        char tmp[5];  
        scanf("%d" ,&n);  
        for(int i=0;i<n;i++) scanf("%d" , &s[i]);  
        sort(s ,s+n , cmp);  
        scanf("%d" , &m);  
        n = min(n , m);  
      
        for(int i=1;i<=m;i++){  
            scanf("%s" ,tmp) ;  
            action[i] = tmp[0]=='p' ? 1 : 2 ;  
            scanf("%d"  , &team[i]);  
            team[i]--;  
        }  
      
        printf("%d\n" , DP(1 , (1<<n) - 1));  
        return 0;  
    }