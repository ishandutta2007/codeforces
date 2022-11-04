/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxN= 150+5;
const int maxT= 50+5;
const int BASE= 51123987;

int n;
int val[3+2];
ll C[maxT][maxT];
ll dp[4][maxT][maxT][maxT];
string s;

inline void setDyn(){
    for (int i=0;i< (int)s.size();i ++){
        int cur= s[i], maxl= (n+2)/3;
        if (cur==1){
            for (int a=1;a<= maxl;a ++)
                for (int b=0;b<= maxl;b ++)
                    for (int c=0;c<= maxl;c ++)
                        dp[cur][a][b][c]= (dp[2][a-1][b][c] + dp[3][a-1][b][c])%BASE;
            dp[cur][1][0][0]= 1;
        }
        if (cur==2){
            for (int a=0;a<= maxl;a ++)
                for (int b=1;b<= maxl;b ++)
                    for (int c=0;c<= maxl;c ++)
                        dp[cur][a][b][c]= (dp[1][a][b-1][c] + dp[3][a][b-1][c])%BASE;
            dp[cur][0][1][0]= 1;
        }
        if (cur==3){
            for (int a=0;a<= maxl;a ++)
                for (int b=0;b<= maxl;b ++)
                    for (int c=1;c<= maxl;c ++)
                        dp[cur][a][b][c]= (dp[1][a][b][c-1] + dp[2][a][b][c-1])%BASE;
            dp[cur][0][0][1]= 1;
        }
    }
}
/*****************************************/
inline ll ans (int a, int b, int c, int cnt){
    for (int i=1;i<= (n%3);i ++)
        val[i]= (n/3)+1;
    for (int i=(n%3)+1;i<= 3;i ++)
        val[i]= (n/3);

    ll ret= 0;
    for (int i=1;i<= 3;i ++){
        ret = ret + (C[a-1][val[1]-1] * C[b-1][val[2]-1]%BASE) * C[c-1][val[3]-1];
        ret%= BASE;
        if (n%3== 0)
            return cnt*ret;
        if (n%3== 1)
            swap (val[i], val[i+1]);
        else
            swap (val[4-i], val[3-i]);
    }
    return cnt*ret;
}
/*****************************************/
inline void setC (){
    C[0][0]= 1;
    for (int i=1;i< maxT;C[0][i++]= 1)
        for (int j=1;j<= i;j ++)
            C[j][i]= (C[j][i-1]+C[j-1][i-1])%BASE;
    
}
/*****************************************/
int main(){
    cin >> n;
    char past= 0;
    int cnt[]= {0, 0, 0, 0};
    for (int i=0;i< n;i ++){
        char ch;
        cin >> ch;
        if (ch!=past){
            cnt[ch-'a'+1]++;
            s+= (ch-'a'+1);
        }
        past= ch;
    }
    setDyn();

    if (cnt[1]==0 || cnt[2]==0 || cnt[3]==0){
        if (n > 2){
            cout << 0 << endl;
            return 0;
        }
        if (n==1){
            cout << 1 << endl;
            return 0;
        }
        if (n==2 && cnt[1]+cnt[2]+cnt[3]==2){
            cout << 1 << endl;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }
    setC ();
    ll res= 0;
    for (int i=1;i<= 3;i ++){
        int maxl= (n+2)/3;
        for (int a=1;a<= maxl;a ++)
            for (int b=1;b<= maxl;b ++)
                for (int c=1;c<= maxl;c ++)
                    res= (res + ans (a,b,c, dp[i][a][b][c]))%BASE;
    }

    cout << res << endl;

    return 0;
}