#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200010, M = N << 1, SIZE = 2750132;
int n, b[M], factor[SIZE], cnt[SIZE], primes[N], tot = 0;
bool st[SIZE];
vector<int> A, B;
//AB
//1. 
//2. 
//
//
int main(){
    for(int i = 2; i <= SIZE; i++){
        if(!st[i]) primes[++tot] = i;
        for(int j = 1; j <= tot && i * primes[j] <= SIZE; j++){
            st[i * primes[j]] = true;
            factor[i * primes[j]] = i;
            if(i % primes[j] == 0) break;
        }
    }

    scanf("%d", &n);
    for(int i = 1; i <= (n << 1); i++){
        scanf("%d", b + i);
        if(st[b[i]]) B.push_back(b[i]);
        else A.push_back(b[i]);
    }
    sort(B.begin(), B.end(), greater<int>() );
    sort(A.begin(), A.end());
    for(int i = 0; i < B.size(); i++){
        if(cnt[B[i]]) cnt[B[i]]--;
        else {
            printf("%d ", B[i]);
            cnt[factor[B[i]]]++;
        }
    }
    for(int i = 0; i < A.size(); i++){
        if(cnt[A[i]]) cnt[A[i]]--;
        else {
            printf("%d ", A[i]);
            cnt[primes[A[i]]] ++;
        }
    }
    return 0;
}