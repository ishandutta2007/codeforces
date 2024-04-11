/*
    Cleaner code :P In case of reading later
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
vector<int> cur,keep,basis;

void ins(int x){
    int now  = x;
    for(int i : basis){
        x = min(x, x^i);
        }
    if(x > 0){
        keep.push_back(now);
        basis.push_back(x);
        for(int i = (int)basis.size() - 1 ; i > 0 ; i --){
            if(basis[i] > basis[i - 1])
                swap(basis[i],basis[i-1]);
            else break;
        }
    }
}


int main(){
    scanf("%d",&n);
    vector<int> s(n);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    sort(s.begin(), s.end());
    int has = 0, pt = 0;
    for(int i = 1 ; i <= 19 ; i++){
        while(pt < n && s[pt] < (1 << i)){
            ins(s[pt++]);
        }
        if((int)basis.size() == i) has = i;
    }
    if(has == 0) return !printf("0 \n0");
    printf("%d\n",has);
    cur = { 0 , 1 };
    for(int i = 1 ;i < has;i++)
        for(int j = (int)cur.size () - 1 ;j >= 0 ; j--){
            cur.push_back(cur[j]*2 + 1);
            cur[j] <<= 1;
    }
    int toprint = 0;
    for(int i:cur){
        toprint = 0;
        for(int j = 0 ; j < has; j++){
            if(i >> j & 1) toprint ^= keep[j];
        }
       printf("%d ",toprint);
    }
}
/*
    Every number from 0 to 2 ^ x-1
    can be written in form of linear combination of basis
    and basis can be written in form of
    linear combination of element in S ?
    We add at most d elements from S
    such that each of them can be written as linear combination of basis
    every permutation of its xor value must be integer from 0 to 2^(x-1)
*/