#include <cstring>
#include <iostream>
using namespace std;

int abs(int x){
    return (x>=0)?x:(-x);
}

int sgn(int x){
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}

int dx[128];
int dy[128];
int n;
char s[128];

bool valid(int x, int y, int dx, int dy){
    if(x==0&&y==0)return true;

    if(dx==0){
       if(x!=0)return false;
       if(sgn(y)!=sgn(dy))return false;
       y=abs(y);dy=abs(dy);
       return y%dy==0;
    }
    if(dy==0){
       if(y!=0)return false;
       if(sgn(x)!=sgn(dx))return false;
       x=abs(x);dx=abs(dx);
       return x%dx==0;
    }

    if(sgn(x)!=sgn(dx)||sgn(y)!=sgn(dy))return false;
    x=abs(x);dx=abs(dx);y=abs(y);dy=abs(dy);
    if(x%dx!=0||y%dy!=0)return false;
    return x/dx==y/dy;
}

int main(){
    int i,a,b;
    cin>>a>>b>>s;n=strlen(s);
    dx[0]=0;
    dy[0]=0;
    for(i=1;i<=n;++i){
        char c=s[i-1];
        switch(c){
            case 'U':
                dx[i]=dx[i-1];
                dy[i]=dy[i-1]+1;
                break;
            case 'D':
                dx[i]=dx[i-1];
                dy[i]=dy[i-1]-1;
                break;
            case 'L':
                dx[i]=dx[i-1]-1;
                dy[i]=dy[i-1];
                break;
            case 'R':
                dx[i]=dx[i-1]+1;
                dy[i]=dy[i-1];
                break;
        }
    }
    bool r=false;
    for(i=0;!r&&i<n;++i){
        if(valid(a-dx[i],b-dy[i],dx[n],dy[n]))r=true;
    }
    if(r)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}