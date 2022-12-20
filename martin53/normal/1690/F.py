class solver_1690F:

    def __init__(self):
        self.n=int(input());
        self.inp=input();
        self.p=list(map(int,input().split(' ')));

        for i in range(self.n):
            self.p[i]=self.p[i]-1;

    def update_answer(self, b):

        mem_b=b;

        a=self.answer;

        while b:
            r=a%b;
            a=b;
            b=r;

        self.answer=self.answer//a*mem_b;

    def solve(self):
        been=[0 for _ in range(0,self.n)];

        self.answer=1;

        for i in range(0,self.n):
            if been[i]==0:

                cur=[];

                j=i;

                while been[j]==0:

                    cur.append(self.inp[j]);
                    been[j]=1;

                    j=self.p[j];

                for c in range(1,len(cur)+1):
                    if len(cur)%c==0:

                        ok=True;

                        for j in range(c,len(cur)):
                            if cur[j]!=cur[j-c]:
                                ok=False;

                        if ok==True:
                            self.update_answer(c);
                            break;

        return self.answer;


t=int(input());

while t:
    t=t-1;

    cur=solver_1690F();

    print(cur.solve());