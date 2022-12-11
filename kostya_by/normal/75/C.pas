program project1;

var
   mna,mnb,mno : array[2..50000] of longint;
   i,j,n,m,h,a,b,l,r,nod,ans : longint;

procedure add(x : longint);
begin
     inc(h);
     mno[h]:=x;
end;

function min(a,b  :longint):longint;
begin
     if a < b then min:=a else min:=b;
end;

procedure sort(l,r : longint);
var
   x,y,i,j : longint;
begin
     i:=l;
     j:=r;
     x:=mno[(l + r) div 2];
     repeat
           while mno[i] < x do inc(i);
           while mno[j] > x do dec(j);
           if i <= j then begin
              y:=mno[i]; mno[i]:=mno[j]; mno[j]:=y;
              inc(i);
              dec(j);
           end;
     until i > j;
     if i < r then sort(i,r);
     if l < j then sort(l,j);
end;

procedure bin(left,right : longint);
var
   x : longint;
begin
     if left > right then exit;
     x:=(left + right) div 2;
     if mno[x] <= r then begin
        if x > ans then ans:=x;
        bin(x + 1, right);
     end else bin(left, x - 1);
end;

begin
     read(a,b);
     m:=a;
     for i:=2 to 50000 do begin
         while m mod i = 0 do begin
               m:=m div i;
               inc(mna[i]);
         end;
     end;
     a:=m;
     m:=b;
     for i:=2 to 50000 do begin
         while m mod i = 0 do begin
               m:=m div i;
               inc(mnb[i]);
         end;
     end;
     b:=m;
     h:=0;
     nod:=1;
     if (a <> 1) and (a = b) then begin
        add(a);
        nod:=a;
     end;
     for i:=2 to 50000 do begin
         for j:=1 to min(mna[i],mnb[i]) do nod:=nod * i;
     end;
     add(nod);
     add(1);
     for i:=2 to trunc(sqrt(nod)) do begin
         if nod mod i = 0 then begin
            add(i);
            add(nod div i);
         end;
     end;
     sort(1,h);
     read(n);
     for i:=1 to n do begin
         read(l,r);
         ans:=-1;
         bin(1,h);
         if mno[ans] < l then writeln('-1') else writeln(mno[ans]);
     end;
end.