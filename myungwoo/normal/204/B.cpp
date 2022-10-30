#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005
typedef pair<int,int> pii;

int N,A[MAXN],B[MAXN],ans=1e9;
map <int,int> cnt;
map <int,int>::iterator it;
vector <pii> arr;

int proc(int v)
{
    int i,k=0;
    for (i=1;i<=N;i++){
        if (A[i] == v) k++;
    }
    if (k >= (N+1)/2) return 0;
    else return (N+1)/2-k;
}

int main()
{
    int i,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%d%d",A+i,B+i);
        if (A[i] == B[i]) cnt[A[i]]++;
        else cnt[A[i]]++, cnt[B[i]]++;
    }
    for (it=cnt.begin();it!=cnt.end();++it){
        arr.push_back(pii(-it->second,it->first));
    }
    sort(arr.begin(),arr.end());
    if (-arr[0].first < (N+1)/2){ puts("-1"); return 0; }
    if (arr.size() == 1){ puts("0"); return 0; }
    for (i=0;i<arr.size();i++){
        if (-arr[i].first < (N+1)/2) break;
        k = proc(arr[i].second);
        if (ans > k) ans = k;
    }
    printf("%d",ans);
}