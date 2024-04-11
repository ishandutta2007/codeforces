#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

vector<int> cnt(100001,0);
vector<vector<int>> Y(100001,vector<int>());
vector<int> M(100001,0);

void INS(int y){
	for(int i=0;i<Y[y].size();i++)cnt[Y[y][i]]++;
}

void DEL(int y){
	for(int i=0;i<Y[y].size();i++)cnt[Y[y][i]]--;
}

bool CHECK(int y){
	int C = 0;
	for(int i=0;i<Y[y].size();i++){
		C += M[Y[y][i]] * cnt[Y[y][i]];
	}
	return C>0;
}

long long get(vector<int> &A){
	reverse(A.begin(),A.end());
	stack<int> S;
	long long ret = 0;
	
	for(int i=0;i<A.size();i++){
		long long last = 0;
		while(CHECK(A[i])){
			last = S.top();
			DEL(last);
			S.pop();
		}
		
		ret = max(ret,A[i] * last);
		S.push(A[i]);
		INS(A[i]);
	}
	
	while(S.size()!=0){
		DEL(S.top());
		S.pop();
	}
	
	return ret;
	
}

int main(){

	int N;
	cin>>N;
	long long ans = 0;
	vector<bool> A(100001,false);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		if(A[x])ans = max(ans,(long long)x);
		A[x]=true;
	}
	
	for(int i=1;i<=100000;i++){
		for(int j=i;j<=100000;j+=i){
			Y[j].push_back(i);
		}
	}
	
	for(int i=1;i<=100000;i++){
		int x = i;

		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				M[i]++;
				x/=j;
				if(x%j==0){
					M[i] = -100;
					break;
				}
			}
		}
		if(x!=1&&M[i]!=-100)M[i]++;
		if(M[i]==-100)M[i]=0;
		else{
			if(M[i]%2==0)M[i]=1;
			else M[i]=-1;
		}		
	}
	
	
	
	for(int i=1;i<=100000;i++){
		vector<int> a;
		for(int j=0;j<=100000;j+=i){
			if(A[j]){
				a.push_back(j / i);
			}
		}
		
		ans = max(ans,get(a)*i);
	}
	
	cout<<ans<<endl;
		
	
	return 0;
}