#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int a[100000];

int main(){
    int N;scanf("%d",&N);

    map<int,int>M;

    int prev=0,ma=0;

    rep(i,N){
        scanf("%d",&a[i]);
        M[a[i]]++;
        while(M.size()>2){
            M[a[prev]]--;
            if(M[a[prev]]==0)M.erase(a[prev]);
            prev++;
        }
        ma=max(ma,i-prev+1);
    }

    printf("%d\n",ma);

    return 0;
}

/*
11
5 4 5 5 6 7 8 8 8 7 6
*/