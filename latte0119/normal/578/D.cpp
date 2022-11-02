#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;
string S;
signed main(){
	cin>>N>>M>>S;
	/*
	
	set<string>t;
	for(int l=0;l<N;l++){
		for(int r=l+1;r<=N;r++){
			string s=S;
			rotate(s.begin()+l,s.begin()+l+1,s.begin()+r);
			if(s!=S)t.insert(s);

			s=S;
			rotate(s.begin()+l,s.begin()+r-1,s.begin()+r);
			if(s!=S)t.insert(s);
		}
	}*/

	int ans=0;
	vint cnt(M);
	for(int i=N-1;i>=0;i--){
		int c=S[i]-'a';
		if(i+1<N&&S[i]!=S[i+1]){
			ans+=N-i-1-cnt[c];
			ans+=cnt[c]*(M-1);
			ans+=(N-i-1-cnt[c])*(M-2);
		}
		cnt[c]++;
	}

	fill(all(cnt),0ll);
	vector<int>st(N);
	for(int i=0;i<N;i++){
		int c=S[i]-'a';
		if(i&&S[i-1]!=S[i]){
			st[i]=1;
			if(i>=3&&S[i-3]==S[i-1]&&S[i-2]==S[i])st[i]+=st[i-2];
			ans+=i-cnt[c]-st[i];
			ans+=cnt[c]*(M-1);
			ans+=(i-cnt[c])*(M-2);

			int tmp=st[i]-1;
			if(i-st[i]*2>=0&&S[i-st[i]*2]==S[i])tmp++;
			ans-=tmp;
		}
		cnt[c]++;
	}
	ans+=(M-1)*N;
	/*
	fill(all(cnt),0ll);
	rep(i,N)cnt[S[i]-'a']++;
	int cur=0;
	while(cur<N){
		int nex=cur;
		while(nex<N&&S[cur]==S[nex])nex++;
		int tmp=M-1;
		tmp+=(cnt[S[cur]-'a']-1)*(M-1);
		tmp+=(N-cnt[S[cur]-'a'])*(M-2);
		ans+=tmp;
		cur=nex;
	}
	rep(i,N-2)if(S[i]==S[i+2]&&S[i]!=S[i+1])ans--;
	*/	
	cout<<ans<<endl;
	return 0;
}