#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
using ll = long long ;
int n;
int a[maxn];
ll k;

int main(){
    scanf("%d %lld", &n ,&k);
    ll mi = (1LL *n * (n + 1)) / 2;
    ll t = k;
    if(k < mi) return !printf("-1");
    k -= mi;
    for(int i = 1 ;i<= n ;i ++){
        a[i] = i;
    }
    cerr <<"k = " << k << endl;
    for(int i = 1 ; k > 0 &&i <= n / 2 + 1; i++){
        //-> change n - i to i
        int dif = n - i - i + 1;
        if(k > 0 && dif > 0){
            if(k > dif){
                k -= dif;
                swap(a[i], a[n - i + 1]);
            }
            else{
               // cout << "?\n";
                swap(a[i], a[i + k]);
                k = 0;
            }
        }
    }
    printf("%lld\n",t - k);
    ll wtf = 0;
    for(int i = 1 ;i <= n; i++)
        wtf += max(i , a[i]);
    fprintf(stderr, "wtf = %lld\n", wtf);
    for(int i = 1 ;i <= n;i++)
        printf("%d%c",i,i == n ? '\n' : ' ');
    for(int i = 1; i <= n;i++){
        printf("%d%c",a[i], i == n? '\n' : ' ');
    }
}
/*
    Virtual Round 592
*/