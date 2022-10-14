#include<bits/stdc++.h>
using namespace std;
int const N=23;
map<string,int>ord={{"H",1},{"He",2},{"Li",3},{"Be",4},{"B",5},{"C",6},{"N",7},{"O",8},{"F",9},{"Ne",10},{"Na",11},{"Mg",12},{"Al",13},{"Si",14},{"P",15},{"S",16},{"Cl",17},{"Ar",18},{"K",19},{"Ca",20},{"Sc",21},{"Ti",22},{"V",23},{"Cr",24},{"Mn",25},{"Fe",26},{"Co",27},{"Ni",28},{"Cu",29},{"Zn",30},{"Ga",31},{"Ge",32},{"As",33},{"Se",34},{"Br",35},{"Kr",36},{"Rb",37},{"Sr",38},{"Y",39},{"Zr",40},{"Nb",41},{"Mo",42},{"Tc",43},{"Ru",44},{"Rh",45},{"Pd",46},{"Ag",47},{"Cd",48},{"In",49},{"Sn",50},{"Sb",51},{"Te",52},{"I",53},{"Xe",54},{"Cs",55},{"Ba",56},{"La",57},{"Ce",58},{"Pr",59},{"Nd",60},{"Pm",61},{"Sm",62},{"Eu",63},{"Gd",64},{"Tb",65},{"Dy",66},{"Ho",67},{"Er",68},{"Tm",69},{"Yb",70},{"Lu",71},{"Hf",72},{"Ta",73},{"W",74},{"Re",75},{"Os",76},{"Ir",77},{"Pt",78},{"Au",79},{"Hg",80},{"Tl",81},{"Pb",82},{"Bi",83},{"Po",84},{"At",85},{"Rn",86},{"Fr",87},{"Ra",88},{"Ac",89},{"Th",90},{"Pa",91},{"U",92},{"Np",93},{"Pu",94},{"Am",95},{"Cm",96},{"Bk",97},{"Cf",98},{"Es",99},{"Fm",100}};
int n,m,tot,flg,a[N],b[N],p[N];
string sa[N],sb[N];
vector<int>e[N];
void dfs(int x,int s,int t){
	if(t>m)
		return flg=1,void();
	if(s==b[t])
		dfs(1,0,t+1);
	for(int i=x,pre=0;i<=n&&!flg&&s+a[i]<=b[t];i++)
		if(!p[i]&&pre<a[i])
			p[i]=t,pre=a[i],dfs(x+1,s+a[i],t),!flg&&(p[i]=0);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>sa[i];
	for(int i=1;i<=m;i++)
		cin>>sb[i];
	sort(sa+1,sa+1+n,[](string a,string b){
		return ord[a]<ord[b];
	}); 
	sort(sb+1,sb+1+m,[](string a,string b){
		return ord[a]<ord[b];
	});
	for(int i=1;i<=n;i++)
		a[i]=ord[sa[i]],tot+=a[i];
	for(int i=1;i<=m;i++)
		b[i]=ord[sb[i]],tot-=b[i];
	if(!tot&&(dfs(1,0,1),flg)){
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
			e[p[i]].push_back(i);
		for(int i=1;i<=m;i++){
			for(int j=0;j<(int)e[i].size()-1;j++)
				cout<<sa[e[i][j]]+"+";
			cout<<sa[e[i].back()]+"->"+sb[i]+"\n";
		}
	}else cout<<"NO\n";
}