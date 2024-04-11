#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=3.1e4;
const int L=16;
const int C=4;
int p[N];
struct Node{
	pair<int,Node*> ch[C+1];
	int ccnt;
	LL cnt;
	LL warpl[L];
	LL warpr[L];
}o[C+1][N];
void work(){
	// cerr<<__FUNCTION__<<endl;
	int n=read(),c=read(),q=read();
	F(i,1,n)p[i]=read();
	F(i,0,c){
		o[i][n+1].ccnt=0;
		o[i][n+1].cnt=1;
	}
	F(i,0,c){
		R(j,n,1){
			Node &nd=o[i][j];
			nd.warpl[0]=0;
			nd.warpr[0]=0;
			nd.ccnt=0;
			nd.cnt=0;
			F(k,0,min(i,n-j)){
				Node *ptr=&o[i-k][j+k+1];
				nd.ch[nd.ccnt++]=make_pair(p[j+k],ptr);
				if(p[j+k]<p[j])nd.warpl[0]+=ptr->cnt;
				else if(p[j+k]>p[j])nd.warpr[0]+=ptr->cnt;
				nd.cnt+=ptr->cnt;
			}
			sort(nd.ch,nd.ch+nd.ccnt);
			F(k,1,L-1){
				if(j+(1<<k)>n)break;
				nd.warpl[k]=nd.warpl[k-1]+o[i][j+(1<<(k-1))].warpl[k-1];
				nd.warpr[k]=nd.warpr[k-1]+o[i][j+(1<<(k-1))].warpr[k-1];
			}
		}
	}
	D(_,q){
		int x=read();
		LL cnt=read()-1;
		if(cnt>=o[c][1].cnt){
			puts("-1");
			continue;
		}
		int curc=c,pos=1;
		int lv=L-1;
		while(true){
			Node &nd=o[curc][pos];
			if(pos+(1<<lv)<=x
			&&cnt>=nd.warpl[lv]
			&&cnt<nd.cnt-nd.warpr[lv]){
				pos+=1<<lv;
				cnt-=nd.warpl[lv];
			}
			else{
				if(lv==0){
					// cerr<<"decide curc="<<curc<<" pos="<<pos<<endl;
					int cid=-1;
					D(i,nd.ccnt){
						Node *nxt=nd.ch[i].second;
						if(cnt>=nxt->cnt){
							cnt-=nxt->cnt;
						}
						else{
							// cerr<<"fst="<<nd.ch[i].first<<" ncnt="<<nxt->cnt<<endl;
							cid=i;
							break;
						}
					}
					assert(cid!=-1);
					int cost=find(p+pos,p+n+1,nd.ch[cid].first)-(p+pos);
					// cerr<<"cost="<<cost<<endl;
					// assert(cost!=0);
					curc-=cost;
					if(pos+cost>=x){
						// cerr<<"> ";
						printf("%d\n",p[pos+cost-(x-pos)]);
						break;
					}
					else{
						pos+=cost+1;
						lv=L-1;
					}					
				}
				else lv--;
			}
		}
	}
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}