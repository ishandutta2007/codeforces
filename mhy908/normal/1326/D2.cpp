#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int t,  n;
char in[2000010], str[2000010], S[2000010];
int A[2000010], N;
void f(){
    //printf("DBG : %s %d %c", S, N, S[N-1]);
    int r=0, p=0;
    for(int i=0; i<N; i++){
        if(i<=r)A[i]=min(A[2*p-i], r-i);
        else A[i]=0;
        while(i-A[i]-1>=0&&i+A[i]+1<N&&S[i-A[i]-1]==S[i+A[i]+1])A[i]++;
        if(r<i+A[i]){
            r=i+A[i];
            p=i;
        }
    }
    int ans=0, ansnum;
   // puts("");
    for(int i=0; i<N; i++){
        //printf("%d : %d\n", i, A[i]);
        if(i==A[i]){
            if(ans<2*A[i]+1){
                ans=2*A[i]+1;
                ansnum=i;
            }
        }
        if(i==N-1-A[i]){
            if(ans<2*A[i]+1){
                ans=2*A[i]+1;
                ansnum=-i;
            }
        }
    }
    //printf("%d %d\n", ans, ansnum);
    if(ansnum>=0){
        for(int i=0; i<=ans; i++){
            if(S[i]>='a'&&S[i]<='z')printf("%c", S[i]);
        }
    }
    else{
        for(int i=N-1-ans; i<N; i++){
            if(S[i]>='a'&&S[i]<='z')printf("%c", S[i]);
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", in+1);
        int len=strlen(in+1);
        for(int i=1; i<=len; i++){
            str[2*i-1]=in[i];
            if(i!=len)str[2*i]='%';
        }
        len=len*2-1;
        int pv=0;
        for(int i=1; i<=len/2; i++){
            if(str[i]!=str[len-i+1]){
                pv=i-1;
                break;
            }
        }
        for(int i=1; i<=pv; i++){
            if(str[i]>='a'&&str[i]<='z')printf("%c", str[i]);
        }
        N=0;
        for(int i=pv+1; i<=len-pv; i++)S[N++]=str[i];
        f();
        for(int i=pv; i>=1; i--){
            if(str[i]>='a'&&str[i]<='z')printf("%c", str[i]);
        }
        puts("");
        for(int i=0; i<=len; i++){
            in[i]=str[i]=S[i]=0;
            A[i]=0;
        }
    }
}