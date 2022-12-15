#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<cmath> 
#define LL long long
using namespace std;
const int N=2e6+100;
const LL P=998244353;
int n,K;
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
char s[N];
char s_new[N];
int Init() {
    int len=strlen(s+1);
    s_new[0]='$';
    s_new[1]='#';
    int j=2; 
    for(int i=1;i<=len;i++) {
        s_new[j++]=s[i];
        s_new[j++]='#';
    } 
    s_new[j]='\0'; 
    return j;
}
int f[N];
int p[N];

int l,r;
int Manacher() {
    int len=Init();
    int max_len=-1;
    int id=0;
    int mx=0;
    l=0;r=0;
    for(int i=1;i<=len;i++) {
        if(i<mx)
            p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]])
            p[i]++;
        if(mx<i+p[i]) {
            id=i;
            mx=i+p[i];
        }
        max_len=max(max_len,p[i]-1); 
    }
    for(int i=1;i<=len;++i){
    	id=(i-p[i])/2;
    	if(id<=(n/2)&&f[id]&&l+r<id+id+p[i]-1&&n-id-p[i]+1>=id) {
    		l=id+p[i]-1;
    		r=id;
		}
		//if(l+r>n) cout<<l<<" "<<r<<" "<<id<<" "<<p[i]-1<<endl;
    	id=(i+p[i])/2;
    	if(id<=((n+1)/2)) continue;
    	//cout<<i<<" "<<p[i]<<" "<<id<<endl;
    	id=n-id+1;
    	if(f[id]&&l+r<id+id+p[i]-1&&n-id-p[i]+1>=id){
    		l=id;
    		r=id+p[i]-1;
		}
		//if(l+r>n) cout<<l<<" "<<r<<" "<<id<<" "<<p[i]-1<<endl;
	}
    return max_len;
}

int main(){
	int T;scanf("%d",&T);
	int x,y;
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i) f[i]=0;
		f[0]=1;f[n+1]=1;
		for(int i=1;i<=n;++i){
			if(s[i]==s[n-i+1]){
				f[i]=1;
				f[n-i+1]=1;
			}
			else break;
		}
		y=Manacher();
		//cout<<l<<" "<<r<<endl;
		for(int i=1;i<=l;++i) printf("%c",s[i]);
		for(int i=n-r+1;i<=n;++i) printf("%c",s[i]);
		cout<<endl;
	}
	return 0;
}