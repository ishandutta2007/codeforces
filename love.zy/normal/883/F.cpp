/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

set<string> st;
char s[401];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        char ss[401];
        for(int i=0;s[i];i++){
            if(s[i]=='u'){
                strcpy(ss+i+2,s+i+1);
                s[i]=s[i+1]='o';
                strcpy(s+i+2,ss+i+2);
            }
        }
        while(1){
            bool flag=false;
            for(int i=0;s[i];i++){
                if(s[i]=='k'&&s[i+1]=='h'){
                    strcpy(ss+i,s+i+1);
                    strcpy(s+i,ss+i);
                    flag=true;
                    break;
                }
            }
            if(!flag)break;
        }
        st.insert(string(s));
    }
    printf("%d\n",st.size());
    return 0;
}