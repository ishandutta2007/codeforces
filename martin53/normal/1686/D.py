class solver_1686D:

    def __init__(self):
        self.a,self.b,self.ab,self.ba=list(map(int,input().split(' ')));
        self.inp=input();
        self.n=len(self.inp);

    def solve(self):

        cnt_a=0;
        cnt_b=0;

        for i in self.inp:
            if i=='A':
                cnt_a=cnt_a+1;
            else:
                cnt_b=cnt_b+1;

        if self.a+self.ab+self.ba != cnt_a or self.b+self.ab+self.ba != cnt_b:
            return "NO";

        both=0;

        ab=[];
        ba=[];

        i=0;

        while i<self.n-1:
            if self.inp[i]!=self.inp[i+1]:
                j=i;

                while j<self.n-1 and self.inp[j]!=self.inp[j+1]:
                    j=j+1;

                if i%2==j%2:
                    both=both+(j-i)//2;
                elif self.inp[i]=='A':
                    ab.append((j-i+1)//2);
                else:
                    ba.append((j-i+1)//2);

                #print("i=",i,"j=",j);

                i=j;

            else:
                i=i+1;

        #print("both=",both,"ab=",ab,"ba=",ba);

        ab.sort();

        for i in range(len(ab)):
            sub=min(self.ab,ab[i])
            self.ab=self.ab-sub;
            ab[i]=ab[i]-sub;

            #print("i= ", i,self.ab,ab[i]);

        ba.sort();

        for i in range(len(ba)):
            sub=min(self.ba,ba[i])
            self.ba=self.ba-sub;
            ba[i]=ba[i]-sub;

        #print("after 1:",self.ab,ab,self.ba,ba);

        #sub ba with ab
        for i in range(len(ab)):
            sub=min(self.ba,ab[i]-1);

            if sub>0:
                self.ba=self.ba-sub;

        #sub ab with ba
        for i in range(len(ba)):
            sub=min(self.ab,ba[i]-1)

            if sub>0:
                self.ab=self.ab-sub;

        #print("final: ",both,self.ab,self.ba);

        if both>=self.ab+self.ba:
            return "YES";

        return "NO";

t=int(input());

while t:
    t=t-1;

    cur=solver_1686D();

    print(cur.solve());