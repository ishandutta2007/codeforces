#include<bits/stdc++.h>
int T,fl,cur,res,x[5],y[5],p[5],c[5],rx[5],ry[5],d[5];
struct value{
	int val;
	bool has;
	inline void reset(){has=0;}
	inline void set(int x){
		if(has){
			if(val!=x)fl=0;
		}else{
			val=x,has=1;
		}
	}
}vx,vy,kx,ky,k;
inline int calc(int a,int b,int c,int d){
	return std::max(std::abs(a-b),std::abs(c-d));
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(scanf("%d",&T);T--;){
		res=-1;
		for(int k=1;k<=4;k++)scanf("%d%d",&x[k],&y[k]),p[k]=k;
		do{
			for(int sta=0;sta<16;sta++){
				fl=1;
				vx.reset(),vy.reset(),kx.reset(),ky.reset(),k.reset();
				for(int i=1;i<=4;i++)c[i]=(sta>>(i-1))&1;
				c[1]?vx.set(x[p[1]]):vy.set(y[p[1]]);
				c[2]?vx.set(x[p[2]]):ky.set(y[p[2]]);
				c[3]?kx.set(x[p[3]]):vy.set(y[p[3]]);
				c[4]?kx.set(x[p[4]]):ky.set(y[p[4]]);
				if(!fl)continue;
				if(vx.has&&kx.has)k.set(kx.val-vx.val);
				if(vy.has&&ky.has)k.set(ky.val-vy.val);
				if(!fl)continue; // assert(k.has);
				if(kx.has)vx.set(kx.val-k.val);
				if(ky.has)vy.set(ky.val-k.val);
				if(!fl)continue; // assert(vx.has||vy.has);
				if(!vx.has){
					d[1]=x[p[1]],d[2]=x[p[2]],d[3]=x[p[3]]-k.val,d[4]=x[p[4]]-k.val;
					std::sort(d+1,d+5),vx.set((d[1]+d[4])/2);
				}
				if(!vy.has){
					d[1]=y[p[1]],d[2]=y[p[3]],d[3]=y[p[2]]-k.val,d[4]=y[p[4]]-k.val;
					std::sort(d+1,d+5),vy.set((d[1]+d[4])/2);
				}
				if(!fl)continue;
				kx.set(vx.val+k.val),ky.set(vy.val+k.val);
				// printf("> %d %d %d %d : %d %d %d %d\n",p[1],p[2],p[3],p[4],c[1],c[2],c[3],c[4]);
				// printf(": %d %d : %d %d : %d %d : %d %d : %d %d\n",k.val,k.has,vx.val,vx.has,vy.val,vy.has,kx.val,kx.has,ky.val,ky.has);
				cur=-1;
				cur=std::max(cur,calc(x[p[1]],vx.val,y[p[1]],vy.val));
				cur=std::max(cur,calc(x[p[2]],vx.val,y[p[2]],ky.val));
				cur=std::max(cur,calc(x[p[3]],kx.val,y[p[3]],vy.val));
				cur=std::max(cur,calc(x[p[4]],kx.val,y[p[4]],ky.val));
				if(cur<res||res==-1){
					res=cur;
					rx[p[1]]=vx.val,ry[p[1]]=vy.val;
					rx[p[2]]=vx.val,ry[p[2]]=ky.val;
					rx[p[3]]=kx.val,ry[p[3]]=vy.val;
					rx[p[4]]=kx.val,ry[p[4]]=ky.val;
				}
			}
		}while(std::next_permutation(p+1,p+5));
		printf("%d\n",res);
		if(~res)printf("%d %d\n%d %d\n%d %d\n%d %d\n",rx[1],ry[1],rx[2],ry[2],rx[3],ry[3],rx[4],ry[4]);
	}
}