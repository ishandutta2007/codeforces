    #include <bits/stdc++.h>
    #define a first
    #define b second
    #define pb push_back
    using namespace std;
    #define endl '\n'
    typedef long long llo;
     
    llo n,m;
    const llo pc=50001;//*52*2*2*5;
    llo par[pc*4*2];
    //llo ss2[pc*4*2];
    bool vis[pc*4*2];
    llo ans[50001];
    //bool vis[pc];
    //llo val[pc*4*2];//malloaing if a node is used
    vector<llo> pre[50001];
    vector<llo> pre2[pc*4*2];
    //vector<llo> pre3[pc*52*4*2];
   // llo le[pc*4*2];
   // llo re[pc*4*2];
     
     
    llo find(llo no){
    	if(par[no]==no){
    		return no;
    	}
    	par[no]=find(par[no]);
    	return par[no];
    }
   // llo cot=0;
    //llo ind7[pc*4*2];
   /* void build(llo no,llo l,llo r){
    	if(l==r){
    		ind7[l]=no;
    	}
    	else{
    		llo mid=(l+r)/2;
    		cot++;
    		//le[no]=cot;
    		build(no+1,l,mid);
    		cot++;
    		re[no]=cot;
    		build(re[no],mid+1,r);
     
    	}
    }*/
    vector<pair<llo,llo>> zz;
    llo find2(llo i){
    	pair<llo,llo> j={i+1,-1};
    	llo x=lower_bound(zz.begin(),zz.end(),j)-zz.begin();
    	x--;
    	return x;
    }
      /* llo x,y;
    void update(llo no,llo l,llo r,llo aa,llo bb,llo ind){
    	if(r<aa or l>bb or aa>bb){
    		return ;
    	}
    	if(aa<=l and r<=bb){
    		if(val[no]==3){
    			x=find(no);
    			y=find(ind);
    			if(x==y){}
    			else{
    				if(ss2[x]>ss2[y]){
    					par[y]=x;
    					ss2[x]+=ss2[y];
    				}
    				else{
    					par[x]=y;
    					ss2[y]+=ss2[x];
    				}
    			}
    			return;
    		}
    		pre2[no].pb(ind);
    		val[no]|=2;
    
    		if(val[no]==3){
    			y=find(no);
    			for(auto xa:pre2[no]){
    				x=find(xa);
    				//llo y=find(no);
    				if(x!=y){
    					if(ss2[x]<ss2[y]){
    						par[x]=y;
    						ss2[y]+=ss2[x];
    					}
    					else{
    						par[y]=x;
    						ss2[x]+=ss2[y];
    						y=x;
    					}
    				}
    				//pre2[no].pop_back();
    			}
    		}
    		
    	}
    	else{
    		llo mid=(l+r)/2;
    		update(no+1,l,mid,aa,bb,ind);
    		update(re[no],mid+1,r,aa,bb,ind);
    	}
    }
 
    void update2(llo no,llo l,llo r,llo i,llo ind){
    	pre2[no].pb(ind);
    	if(val[no]==3){
    		x=find(no);
    		y=find(ind);
    		if(x==y){
     
    		}
    		else{
    			if(ss2[x]>ss2[y]){
    				par[y]=x;
    				ss2[x]+=ss2[y];
    			}
    			else{
    				par[x]=y;
    				ss2[y]+=ss2[x];
    			}
    		}
    		//par[x]=y;
    	}
    	else{
    		val[no]|=1;
    		if(val[no]==3){
    			y=find(no);
    			for(auto xa:pre2[no]){
    				x=find(xa);
    				//llo y=find(no);
    				//par[x]=y;
    				if(x!=y){
    					if(ss2[x]<ss2[y]){
    						par[x]=y;
    						ss2[y]+=ss2[x];
    					}
    					else{
    						par[y]=x;
    						ss2[x]+=ss2[y];
    						y=x;
    					}
    				}
    				//pre2[no].pop_back();
    			}
    		}
    	}
    	
     
    	
    	
     
    	
    	if(l<r){
    		llo mid=(l+r)/2;
    		if(i<=mid){
    			update2(no+1,l,mid,i,ind);
    		}
    		else{
    			update2(re[no],mid+1,r,i,ind);
    		}
    	}
    }*/
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cin>>n>>m;
    	vector<pair<bool,pair<llo,llo>>> ss;
    	vector<pair<llo,llo>> xx;
    	set<pair<pair<llo,llo>,llo>> ee;
    	for(llo i=0;i<m;i++){
    		string s;
    		llo aa,bb;
    		cin>>s;
    		cin>>aa>>bb;
    		if(s=="block"){
    			xx.pb({aa,bb});
    			ss.pb({0,{aa,bb}});
    			ee.insert({{aa,bb},i});
    		}
    		else{
    			ss.pb({1,{aa,bb}});
    		}
    	}
    	sort(xx.begin(),xx.end());
    	vector<pair<llo,llo>> yy;
     
    	for(llo i=0;i<xx.size();i++){
    		if(i==0){
    			if(xx[0].a>0){
    				yy.pb({0,xx[0].a-1});
    			}
    		}
    		yy.pb(xx[i]);
    		llo ne=(1LL<<n)-1;
    		if(i+1<xx.size()){
    			ne=xx[i+1].a-1;
    		}
    		if(ne>xx[i].b){
    			yy.pb({xx[i].b+1,ne});
    		}
    	}
    	if(xx.size()==0){
    		yy.pb({0,(1LL<<n)-1});
    	}
    	
    	for(auto j:yy){
    		if(j.a==j.b){
    			zz.pb(j);
    		}
    		else{
    			llo ind=-1;
    			llo su=0;
    			for(llo i=n-1;i>=0;i--){
    				if(((1LL<<i)&j.a)!=((1LL<<i)&j.b)){
    					ind=i;
    					break;
    				}
    				su+=((1LL<<i)&j.a);
    			}
    			pair<llo,llo> cur;
    			cur.a=j.a;
    			cur.b=su+((1LL<<(ind)))-1;
    			while(cur.a<=cur.b){
    				zz.pb({cur.a,cur.b});
    				break;
    				llo ind2=-1;
    				for(llo i=0;i<ind;i++){
    					if((1LL<<i)&cur.a){
    						ind2=i;
    						break;
    					}
    				}
    				if(ind2==-1){
    					zz.pb({cur.a,cur.b});
    					break;
    				}
    				llo ne=cur.a+(1LL<<ind2)-1;
    				zz.pb({cur.a,ne});
    				cur.a=ne+1;
    			}
    			pair<llo,llo> cur2;
    			cur2.b=j.b;
    			cur2.a=su+(1LL<<ind);
    			while(cur2.a<=cur2.b){
    				zz.pb({cur2.a,cur2.b});
    				break;
    				llo ind2=-1;
    				for(llo i=ind-1;i>=0;i--){
    					if(((1LL<<i)&cur2.a)!=((1LL<<i)&cur2.b)){
    						ind2=i;
    						break;
    					}
    				}
    				if(ind2==-1){
    					zz.pb({cur2.a,cur2.b});
    					break;
    				}
    				zz.pb({cur2.a,cur2.a+(1LL<<ind2)-1});
    				cur2.a+=(1LL<<ind2);
    			}
    		}
    	}
     
    	/*for(auto j:zz){
    		cout<<j.a<<" "<<j.b<<endl;
    	}*/
    	//build(0,0,zz.size()-1);
     
    	for(llo i=0;i<=zz.size();i++){
    		par[i]=i;
    	}
    	for(llo i=0;i<zz.size();i++){
    		auto j=ee.lower_bound({{zz[i].a+1,-1},-1});
    		if(j!=ee.begin()){
    			j--;
    			pair<pair<llo,llo>,llo> no=(*j);
    			if(zz[i].a>=no.a.a and zz[i].b<=no.a.b){
    				pre[no.b].pb(i);
    				continue;
    			}
    		}
    		pre[m-1].pb(i);
    	}
    	assert(zz.size()<pc*52*4);
    	for(llo i=m-1;i>=0;i--){
    		//cout<<i<<":"<<endl;
    		for(auto j:pre[i]){
    			for(auto jj:pre2[j]){
    				llo xa=find(jj);//ind7[jj]);
					llo ya=find(j);;

					par[xa]=ya;
    			}
    			vis[j]=1;
    			pair<llo,llo> cur=zz[j];
    			//cout<<j<<":"<<cur.a<<","<<cur.b<<endl;
    			llo ind3=-1;
    			for(llo i=0;i<n;i++){
    				if(((1LL<<i)&cur.a)!=((1LL<<i)&cur.b)){
    					continue;
    				}
    				ind3=i;
    				break;
    			}
    			ind3=0;
    			/*if(ind3==-1){
    				continue;
    			}*/
    			for(llo ii=ind3;ii<n;ii++){
    				pair<llo,llo> cur2=cur;
    				cur2.a^=(1LL<<ii);
    				cur2.b^=(1LL<<ii);
    				llo aa=find2(cur2.a);
    				llo bb=find2(cur2.b);
    				if(aa>bb){
    					swap(aa,bb);
    				}
    				//cout<<j<<"<"<<aa<<":"<<bb<<endl;
    				for(llo jj=aa;jj<=bb;jj++){

    					if(vis[jj]==1){
    						llo xa=find(jj);//ind7[jj]);
    						llo ya=find(j);;

    						par[xa]=ya;
    				/*		if(x==y){
     
				    		}
				    		else{
				    			if(ss2[x]>ss2[y]){
				    				par[y]=x;
				    				ss2[x]+=ss2[y];
				    			}
				    			else{
				    				par[x]=y;
				    				ss2[y]+=ss2[x];
				    			}
				    		}*/
    					}
    					else{
    						pre2[jj].pb(j);
    					}
    				}

    				//update(0,0,zz.size()-1,aa,bb,ind7[j]);
    				//update2(0,0,zz.size()-1,j,ind7[j]);
    			}
    		}
    	/*	for(llo jj=0;jj<zz.size();jj++){
    			cout<<find(jj+ac)<<",";
    		}
    		cout<<endl;*/
    		if(ss[i].a==1){
    			llo x=find(find2(ss[i].b.a));
    			llo y=find(find2(ss[i].b.b));
    			if(x==y){
    				ans[i]=1;
    			}
    			else{
    				ans[i]=-1;
    			}
    		}
    	}
    	for(llo i=0;i<m;i++){
    		if(ans[i]==1){
    			cout<<1<<endl;
    		}
    		else if(ans[i]==-1){
    			cout<<0<<endl;
    		}
    	}
    	/*for(auto j:zz){
    		cout<<j.a<<","<<j.b<<endl;
    	}*/
     
     
     
     
     
     
     
    	return 0;
    }