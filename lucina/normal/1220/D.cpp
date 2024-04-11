#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n;
long long x;
vector<long long> group[71];
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        group[__builtin_ctzll(x)].push_back(x);
    }
    int ma = 0, mark = 0;
    for(int i=0;i<=65;i++){
        if((int)group[i].size() > ma){
            ma = (int)group[i].size();
            mark = i;
        }
    }
    printf("%d\n", n - ma);
    for(int i=0;i<=65;i++){
        if(i != mark){
            for(long long j:group[i]){
                printf("%lld ",j);
            }
        }
    }
}
/**
    Assume that in the same set there is
    X = 2^a * x, Y = 2^b * y where x,y is odd and a<b
    Consider X * (k1) = Y * (k2)
    2^a * k1 * x = 2^b * y * k2
    k1 * x = 2^(b-a) * y * k2
    Set k1 = 2^(b-a) *y,k2 = 1
    is one of the valid answer
    and k1 + k2 is odd
    So the number in the same set must be in the form 2^(X) * b where b is some odds
    and X is all equal
 
    Why is this always valid?
    Write up some linear combination
 
    2^X(b1* k1 + b2* k2 + b3 * k3 + ... +b_n * k_n) = 0
    b1 * k1 + b2 * k2 + ...... + b_n * k_n = 0
    (k1+k2 + ... + k_n) mod 2 = 0
    So there no cycle of odd length!
    */