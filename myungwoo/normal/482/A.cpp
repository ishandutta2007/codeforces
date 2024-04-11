#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    vector <int> arr;
    scanf("%d%d", &N, &K);
    for (int i=1;i<=N-K;i++) arr.push_back(i);
    for (int i=K,j=0;i>0;i--,j^=1){
        arr.push_back(arr.back() + (j ? -1 : 1) * i);
    }
    for (int v: arr) printf("%d ", v); puts("");
}