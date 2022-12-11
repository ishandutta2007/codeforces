#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int N,K,A[MN],B[MN],pos,ans;
bool ch;
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0; i<N; i++) scanf("%1d",&A[i]);
    pos = K;
    while(pos<N){
        if(A[pos]==A[pos%K]){
            pos++;
            continue;
        }
        if(A[pos]>A[pos%K]) ch = 1;
        break;
    }
    printf("%d\n",N);
    if(ch){
        pos = K-1;
        A[pos]++;
        while(A[pos]>9){
                A[pos]=0;
                A[pos-1]++;
                pos--;
        }
    }
    for(int i=0; i<N; i++) printf("%d",A[i%K]);
}