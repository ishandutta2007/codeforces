#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 5005;
int N, gap, pos[MAXN], tmp[MAXN], lcp[MAXN]; char S[MAXN];
long long D[MAXN];

bool sufCmp(int i, int j)
{
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

const long long mod = 1000000007;
void add(long long &a, long long b)
{
    a += b;
    if (a >= mod) a -= mod;
}

void bye(vector<int> &wait, int l)
{
    sort(wait.rbegin(),wait.rend());
    for (int x : wait) add(D[x+l],D[x]);
}

int main()
{
    scanf ("%*d%s",S);

    N = strlen(S);
    vector<int> sa(N);
    for (int i=0;i<N;i++) sa[i] = i, pos[i] = S[i];
    
    for (gap=1;;gap<<=1)
    {
        sort(sa.begin(), sa.end(), sufCmp);
        for (int i=0;i<N-1;i++) tmp[i+1] = tmp[i] + sufCmp(sa[i],sa[i+1]);
        for (int i=0;i<N;i++) pos[sa[i]] = tmp[i];
        if (tmp[N-1] == N-1) break;
    }

    for (int i=0,k=0;i<N;i++) if (pos[i] != N - 1)
    {
        for (int j=sa[pos[i]+1];S[i+k]==S[j+k];) k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }

    D[0] = 1;
    for (int l=1;l<=N;l++){
        vector<int> wait;
        for (int i=0;i<N;i++) if (sa[i] <= N - l){
            if (i){
                if (lcp[i-1] < l){
                    bye(wait,l);
                    wait.clear();
                }
            }
            if (S[sa[i]] != '0') wait.push_back(sa[i]);
        }
        bye(wait,l);
    }
    printf ("%lld\n",D[N]);

    return 0;
}