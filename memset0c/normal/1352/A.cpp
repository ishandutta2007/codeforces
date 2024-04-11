#include<bits/stdc++.h>
template<class T> inline void read(T &x){
    x=0; register char c=getchar(); register bool f=0;
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
int T,n;
int main(){
    read(T);
    while(T--){
        std::vector<int> a,b;
        read(n);
        a.push_back(n%10);
        a.push_back((n/10)%10*10);
        a.push_back((n/100)%10*100);
        a.push_back((n/1000)%10*1000);
        a.push_back((n/10000)%10*10000);
        for(int x:a)if(x)b.push_back(x);
        printf("%lu\n",b.size());
        for(int x:b)printf("%d ",x);
        putchar('\n');
    }
}