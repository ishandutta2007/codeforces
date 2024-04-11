#include <bits/stdc++.h>
using namespace std;

#define val(arr, p) (bool)(arr[p>>5]&(1U<<(p&31)))
#define pb push_back
#define sz(v) ((int)(v).size())
typedef long long lld;

int T, N=2000, M;
unsigned mat[2000][64];
char buf[999];

int main()
{
    scanf("%d", &M);
    for (int i=0;i<M;i++){
        scanf("%s", buf);
        int n = strlen(buf);
        reverse(buf, buf+n);
        vector <lld> tmp((n-1)/8+1, 0);
        for (int i=n;i--;)
            tmp[i/8] = tmp[i/8]*10 + buf[i]-'0';
        for (int j=0;j<250;j++){
            int v = tmp[0] & 255;
            for (int k=0;k<8;k++) if (v & (1 << k)){
                mat[j*8+k][i>>5] ^= (1U << (i&31));
            }
            for (int k=sz(tmp)-1;k>0;k--){
                tmp[k-1] += (tmp[k] & 255) * (lld)1e8;
                tmp[k] >>= 8;
            } tmp[0] >>= 8;
        }
    }
    vector <int> igen;
    for (int i=0;i<M;i++){
        int t = sz(igen);
        bool sw = 0;
        for (int j=t;j<N;j++){
            if (val(mat[j], i)){
                if (t != j){
                    for (int k=0;k<64;k++) swap(mat[t][k], mat[j][k]);
                }
                sw = 1;
                break;
            }
        }
        if (!sw){
            vector <int> arr;
            for (int j=0;j<t;j++)
                if (val(mat[j], i)) arr.pb(igen[j]);
            printf("%d", sz(arr));
            for (int t: arr) printf(" %d", t); puts("");
            continue;
        }
        igen.pb(i);
        puts("0");
        for (int j=0;j<N;j++) if (t != j && val(mat[j], i)){
            for (int k=0;k<64;k++) mat[j][k] ^= mat[t][k];
        }

/*      for (int j=0;j<15;j++){
            for (int k=0;k<M;k++) printf("%d ", val(mat[j], k)); puts("");
        }
        puts("-------------\n");*/
    }
}