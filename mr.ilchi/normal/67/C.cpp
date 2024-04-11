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
#include <cstdio>
#include <cstring>

using namespace std;

const int maxL= 4000+5;

int ti, td, tr, ts;

char s[maxL], M[maxL];
int sizeS, sizeM;
int next[maxL], near[maxL];
int dp[maxL][maxL];

inline void setDyn(){
    for (int i=0;i<=sizeM;i++)
        dp[0][i]= ti*i;

    memset (next, -1, sizeof next);
    for (int i=0;i<sizeS;i++){
        dp[i+1][0]= (i+1)*td;
        memset (near, -1, sizeof near);
        for (int j=0;j<sizeM;j++){
            int ii= i+1, jj= j+1;
            if (s[i]==M[j])
                dp[ii][jj]= dp[i][j];
            else{
                
                dp[ii][jj]= min (dp[i][j] + tr, dp[i][jj] + td);
                dp[ii][jj]= min (dp[ii][jj], dp[ii][j] + ti);

                if (next[M[j]]!=-1 && ii>1 && jj>1){
                    int tmp= next[M[j]];
                    int diff= (i-tmp-1)*td + ts;
                    dp[ii][jj]= min (dp[ii][jj], dp[tmp][jj-2] + diff + tr);
                    if (near[s[i]]!=-1){
                        dp[ii][jj]= min (dp[ii][jj], dp[tmp][near[s[i]]] + diff + (j-near[s[i]]-1)*ti);
                    }
                }
            }
            near[M[j]]= j;
        }
        next[s[i]]= i;
    }
}
/*****************************************/
int main(){
    cin >> ti >> td >> tr >> ts;
    cin >> s >> M;
    
    while (s[sizeS])
        sizeS++;

    while (M[sizeM])
        sizeM++;

    setDyn();

    cout << dp[sizeS][sizeM] << endl;

    return 0;   
}