#include<bits/stdc++.h>
using namespace std;
const int MAXN=1111;
map<string,int> M;
string a,b,c;

int wej[MAXN];
vector<int> wyj[MAXN];
int wyn[MAXN];

main(){
	int n;scanf("%d",&n);
	int nr=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		for(int i=0;i<a.size();i++){
			if(a[i]>='A'&&a[i]<='Z'){
				a[i]+=('a'-'A');
			}
		}
		for(int i=0;i<c.size();i++){
			if(c[i]>='A'&&c[i]<='Z'){
				c[i]+=('a'-'A');
			}
		}
		//cout<<a<<" "<<b<<" "<<c<<endl; 
		if(M.find(a)==M.end()){
			nr++;M[a]=nr;
		}	
		int nra=M[a];
		wej[nra]++;
		if(M.find(c)==M.end()){
			nr++;M[c]=nr;
		}	
		int nrc=M[c];
		wyj[nrc].push_back(nra);
		//cout<<a<<" "<<nra<<";; "<<c<<" "<<nrc<<endl;
	}
	int st=M["polycarp"];
	//printf("%d\n",st);
	queue<int> Q;Q.push(st);
	wyn[st]=1;
	int odp=1;
	while(!Q.empty()){
		int a=Q.front();Q.pop();
		odp=max(odp,wyn[a]);
		for(auto b:wyj[a]){
			wej[b]--;
			wyn[b]=max(wyn[a]+1,wyn[b]);
			if(wej[b]==0) Q.push(b);
		}
	}
	printf("%d\n",odp);
}