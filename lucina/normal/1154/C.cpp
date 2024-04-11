#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a,b,c,st,ss;
int d,e,f;
int cal(int x,int y){
    x=x+st;
    while((((x%7)+7)%7)!=y){
        x--;
    }
    int fuck=st;
    while(((fuck%7)+7)%7!=y)
        fuck++;
    return max(0,(x-fuck)/7+1);
}

int main(){
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<7;i++){
        st=i;
        int l=0,r=a+b+c,mid,ans=0;
        while(l<=r){
            mid=(0ll+l+r)>>1;
            d=(cal(mid,0)+cal(mid,3)+cal(mid,6));
            e=(cal(mid,1)+cal(mid,5));
            f=(cal(mid,2)+cal(mid,4));
            if((d<=a)&&(e<=b)&&(f<=c)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ss=max(ss,ans);
    }
    printf("%d\n",ss+1);
}