#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 1E20
using namespace std;
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>= '0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
int a,b;
double ans1=-1,ans2=-1;
int main()
{
    Read(a),Read(b);
    if(a==b){
        printf("%.12lf\n",(double)b);
        return 0;
    }
    if(a<b){
        printf("-1");
        return 0;
    }
    int t=a-b,c;
    c=t/b;
    if(c&1)
        c--;
    while(1.0*t/c>=b)
        c+=2;
    c-=2;
    if(1.0*t/c>=b)
        ans1=1.0*t/c;
    t=a+b;
    c=t/b;
    if(c&1)
        c--;
    while(1.0*t/c>=b)
        c+=2;
    c-=2;
    if(1.0*t/c>=b)
        ans2=1.0*t/c;
    if(ans1==-1&&ans2==-1){
        printf("-1");
        return 0;
    }
    else if(ans2==-1||ans1==-1)
        ans2=max(ans1,ans2);
    else ans2=min(ans1,ans2);
    printf("%.12lf",ans2);
}