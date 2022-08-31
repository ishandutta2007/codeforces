#define F(x) for(i=0;i<n;++i)printf("%d ",x);
i,n;main(){scanf("%d",&n);if(n&1){F(i)F(i)F(2*i%n)}else puts("-1");return 0;}