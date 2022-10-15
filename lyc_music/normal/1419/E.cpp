//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int T,n,nn,bl,tot,tot1;
vector<int>v,ans,v1;
map<int,int>mp,mp1;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();nn=n;
		v.clear();
		v1.clear();
		ans.clear();
		mp.clear();
		bl=tot=tot1=0;
		mp1.clear();
		for (int i=2;i*i<=nn;i++)
		{
			if (n%i==0) v.push_back(i);
			if (nn%i==0) 
			{
				v1.push_back(i);
				if (nn/i!=i)
				v1.push_back(nn/i);
			}
			while (n%i==0) 
			{	
				n/=i;
//				if (!bl) tot++; else tot1++;E
			}bl=1;
		}
		v1.push_back(nn);
		if (n!=1) 
		{
			v.push_back(n);
//			if (!bl) tot++; else tot1++;
		}
//		cout<<v.size()<<endl;
		v.push_back(v[0]);
		for (int i=0;i<v.size()-1;i++)
		{
			mp[v[i]]=1;
			if (i<v.size()-2||v.size()>3) mp[v[i]*v[i+1]]=1;
//			cout<<i<<" "<<v.size()<<" "<<nn<<endl;
			if (i==v.size()-2&&v.size()==3&&nn>3) mp[nn]=1;
		}
		for (int i=0;i<v.size()-1;i++)
		{
			ans.push_back(v[i]);
			for (int j=0;j<v1.size();j++)
			  if (v1[j]%v[i]==0&&(!mp[v1[j]]))
			  {
			  	ans.push_back(v1[j]);
//			  	cout<<"!"<<v
			  	mp[v1[j]]=1;
			  }
			if (v.size()>3||i<v.size()-2) ans.push_back(v[i]*v[i+1]);
			if (i==v.size()-2&&v.size()==3&&v1.size()>3) ans.push_back(nn);
		}
		for (int i=0;i<ans.size();i++)
		  writesp(ans[i]);
		puts("");
		if (v.size()-1==2&&v1.size()<=3) writeln(1); else writeln(0);
//		cout<<v1.size()<<endl;
	}
}