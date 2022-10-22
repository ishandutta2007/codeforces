#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int pos,int range)
{string x;
 for(int i=0;i<n;++i) x+='0';
 for(int i=pos-1;i<range+pos-1;++i) x[i]='1';
 cout<<"? "<<x<<'\n';
 fflush(stdout);
 int ret;cin>>ret;
 return ret;
}main()
{cin>>n;
 int res=ask(0,0);
 int res2=ask(1,1);
 int beg;
 if(res2==res+1)beg=0;else beg=1;
 int d=1024,pos=1;
 while(d>>=1)
 {if(d+pos>n)continue;
  int cur=ask(pos,d)-res;
  if(d==(1-beg-beg)*cur)pos+=d;
 }
 if(beg)cout<<"! "<<pos<<" 1"<<'\n';
 else cout<<"! "<<"1 "<<pos<<'\n';
 fflush(stdout);
}