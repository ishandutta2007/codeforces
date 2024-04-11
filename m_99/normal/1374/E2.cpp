#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

void go(vector<pair<long long,int>> &a){
	a.insert(a.begin(),make_pair(0LL,-1));
	rep(i,a.size()-1){
		a[i+1].first += a[i].first;
	}
}

int main(){
	
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<pair<long long,int>> AB,A,B,N;
	
	rep(i,n){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(b&&c)AB.emplace_back(a,i);
		else if(b)B.emplace_back(a,i);
		else if(c)A.emplace_back(a,i);
		else N.emplace_back(a,i);
	}
	
	sort(AB.begin(),AB.end());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
	go(AB);
	go(A);
	go(B);
	
	
	long long ans = Inf;
	auto aaaa = A,bbbb = B,aabb = AB,nnnn = N;
	{
		priority_queue<pair<long long,int>> Q;
		long long sum = 0LL;
		while(A.size()>k+1){
			sum += A.back().first - A[A.size()-2].first;
			Q.emplace(A.back().first - A[A.size()-2].first,A.back().second);
			A.pop_back();
		}
		while(B.size()>k+1){
			sum += B.back().first - B[B.size()-2].first;
			Q.emplace(B.back().first - B[B.size()-2].first,B.back().second);
			B.pop_back();
		}
		
		int mm = min((int)A.size(),(int)B.size())-1;
		
		
		
		rep(i,N.size()){
			sum += N[i].first;
			Q.push(N[i]);
		}

		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> uQ;

		rep(i,AB.size()){
			int x = max(0,k-i);
			int need = m-(x*2+i);
			if(x>=0&&x<=mm&&need<=Q.size()+uQ.size()&&need>=0){
				while(Q.size() > need){
					sum -= Q.top().first;
					uQ.push(Q.top());
					Q.pop();
				}
				while(Q.size()<need){
					sum += uQ.top().first;
					Q.push(uQ.top());
					uQ.pop();
				}
				while(uQ.size()>0&&uQ.top().first < Q.top().first){
					auto X = Q.top();
					Q.pop();
					auto Y = uQ.top();
					uQ.pop();
					sum -= X.first;
					sum += Y.first;
					Q.push(Y);
					uQ.push(X);
				}
				long long temp = AB[i].first + A[x].first + B[x].first + sum;
				ans = min(ans,temp);
			}
			if(x!=0){
				if(A.size()>x){
					sum += A[x].first - A[x-1].first;
					Q.emplace(A[x].first - A[x-1].first,A[x].second);
				}
				if(B.size()>x){
					sum += B[x].first - B[x-1].first;
					Q.emplace(B[x].first - B[x-1].first,B[x].second);
				}
			}
		}
	}
	if(ans==Inf){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;
	
	A = aaaa;
	B = bbbb;
	AB = aabb;
	N = nnnn;
	
	{
		priority_queue<pair<long long,int>> Q;
		long long sum = 0LL;
		while(A.size()>k+1){
			sum += A.back().first - A[A.size()-2].first;
			Q.emplace(A.back().first - A[A.size()-2].first,A.back().second);
			A.pop_back();
		}
		while(B.size()>k+1){
			sum += B.back().first - B[B.size()-2].first;
			Q.emplace(B.back().first - B[B.size()-2].first,B.back().second);
			B.pop_back();
		}
		
		int mm = min((int)A.size(),(int)B.size())-1;
		
		
		
		rep(i,N.size()){
			sum += N[i].first;
			Q.push(N[i]);
		}
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> uQ;
		rep(i,AB.size()){
			int x = max(0,k-i);
			int need = m-(x*2+i);
			if(x>=0&&x<=mm&&need<=Q.size()+uQ.size()&&need>=0){
				while(Q.size() > need){
					sum -= Q.top().first;
					uQ.push(Q.top());
					Q.pop();
				}
				while(Q.size()<need){
					sum += uQ.top().first;
					Q.push(uQ.top());
					uQ.pop();
				}
				while(uQ.size()>0&&uQ.top().first < Q.top().first){
					auto X = Q.top();
					Q.pop();
					auto Y = uQ.top();
					uQ.pop();
					sum -= X.first;
					sum += Y.first;
					Q.push(Y);
					uQ.push(X);
				}
				long long temp = AB[i].first + A[x].first + B[x].first + sum;
				if(temp==ans){
					vector<int> inds;
					rep(j,i){
						inds.push_back(AB[j+1].second);
					}
					rep(j,x){
						inds.push_back(A[j+1].second);
						inds.push_back(B[j+1].second);
					}
					while(Q.size()>0){
						inds.push_back(Q.top().second);
						Q.pop();
					}
					
					rep(j,m){
						if(j!=0)cout<<' ';
						cout<<inds[j]+1;
					}
					cout<<endl;
					
					return 0;
				}
			}
			if(x!=0){
				if(A.size()>x){
					sum += A[x].first - A[x-1].first;
					Q.emplace(A[x].first - A[x-1].first,A[x].second);
				}
				if(B.size()>x){
					sum += B[x].first - B[x-1].first;
					Q.emplace(B[x].first - B[x-1].first,B[x].second);
				}
			}
		}
	}
	
	return 0;
}