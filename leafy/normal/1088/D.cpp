#include<bits/stdc++.h>
using namespace std;
int ask(int c,int d){
    printf("? %d %d\n",c,d);
    int ans;
    cin >> ans;
    return ans;
}
int main()
{
    cout.flush();
    int a=0,b=0,big=ask(0,0);
    for(int i=29;i>=0;i--){
        int f=ask(a^(1<<i),b),s=ask(a,b^(1<<i));
        if (f==s){
            if (big==1) a^=(1<<i);
            else b^=(1<<i);
            big=f;
        }
        else if (f==-1){
            a^=(1<<i);
            b^=(1<<i);
        }
    }
    printf("! %d %d\n",a,b);
    return 0;
}