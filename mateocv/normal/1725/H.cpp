#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

vector<int> wh[3];

int main(){FIN;
	int n; cin>>n;
	vector<int> am(3);
	fore(i,0,n){
		int x; cin>>x;
		wh[x%3].pb(i);
		am[x%3]++;
	}
	
	fore(z,0,3){
	
		//incluyo al menos uno de la mascara
		fore(i,0,1<<3) fore(j,0,1<<3){
			
			int am1=0,am2=0;
			
			vector<vector<int>> need(2,vector<int>(3));
			vector<int> rem=am;
			
			fore(x,0,3){
				int me=(i&(1<<x))>0;
				int he=(j&(1<<x))>0;
				
				if(me&&!he) need[0][x]=rem[x], am1+=rem[x], rem[x]=0;
				if(!me&&he) need[1][x]=rem[x], am2+=rem[x], rem[x]=0;
				if(me&&he) need[0][x]=1, need[1][x]=1, am1++, am2++, rem[x]-=2;
			}
			
			int bad=0;
			
			//no puse de un color que tenia que poner
			fore(x,0,3) if(!need[0][x] && !need[1][x] && am[x]) bad=1;
			
			//puse de mas de los que tenia de un tipo
			fore(x,0,3) if(rem[x]<0) bad=1;
			
			//puse de mas en un grupo
			if(max(am1,am2)>n/2) bad=1;
			
			//puse pares malos
			fore(x,0,3) fore(y,0,3) if(need[0][x]&&need[1][y] && ((x+y)*(x+y)+(x*y))%3==z) bad=1;
			
			if(bad)continue;
			
			fore(x,0,3){
				int me=(i&(1<<x))>0;
				int he=(j&(1<<x))>0;
				
				if(!me||!he) continue;
				
				int tome=min(n/2-am1, rem[x]);
				
				am1+=tome;
				am2+=rem[x]-tome;
				
				need[0][x]+=tome;
				need[1][x]+=rem[x]-tome;
				
				rem[x]=0;
			}
			
			if(am1!=am2)continue;
			
			//printear respuesta
			
			string ans(n,'2');
			
			fore(x,0,3){
				fore(i,0,need[0][x]) ans[wh[x].back()]='0', wh[x].pop_back();
				fore(i,0,need[1][x]) ans[wh[x].back()]='1', wh[x].pop_back();
				assert(SZ(wh[x])==0);
			}
			
			cout<<z<<"\n";
			cout<<ans<<"\n";
			exit(0);
		}
	}
	
	cout<<"-1\n";
}