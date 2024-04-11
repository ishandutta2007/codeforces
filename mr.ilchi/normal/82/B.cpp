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
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxN= 300 + 10;

int n;
int mini;
int cnt[maxN];
vector <int> P;
vector <int> Q[200*200];
vector <int> ans[maxN];

int main(){
    scanf ("%d", &n);

    int mini= 300;

    int N= (n*(n-1))/2;

    for (int i=1;i<=N;i++){
        int len; scanf ("%d", &len);
        for (int j=1;j<=len;j++){
            int x; scanf ("%d", &x);
            Q[i].push_back (x);
        }
        sort (Q[i].begin(), Q[i].end());
        mini= min (Q[i][0], mini);
    }

    for (int i=1;i<=N;i++) if (Q[i][0]==mini)
        P.push_back (i);

    if (n==2){
        cout << 1 << ' ' << Q[1][0] << endl;
        cout << Q[1].size()-1 << ' ' ;
        for (int i=1;i<(int)Q[1].size();i++)
            cout << Q[1][i] << ' ';
        cout << endl;
        return 0;
    }

    for (int i=0;i<2;i++){
        int now= P[i];
        for (int j=0;j< (int)Q[now].size();j++)
            cnt[Q[now][j]]++;
    }

    for (int i=1;i<300;i++) if (cnt[i]==2)
        ans[1].push_back (i);

    for (int i=0;i<(int)P.size();i++){
        int now= P[i];
        for (int j=0;j<(int)Q[now].size();j++) if (cnt[Q[now][j]]!=2)
            ans[i+2].push_back (Q[now][j]);
    }

    for (int i=1;i<=n;i++){
        cout << ans[i].size() << ' ';
        for (int j=0;j<(int)ans[i].size();j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}