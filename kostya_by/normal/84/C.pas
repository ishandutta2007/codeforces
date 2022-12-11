program project1;

const eps = 1e-9;

type ttarget = record
     left, right, r, x, status, num : longint;
end;

var
   target : array[0..10010] of ttarget;
   ans,x1,y1,r,n,m,res,i : longint;
   s : double;

procedure sort(l,r : longint);
var
   i,j : longint;
   x1,y1 : ttarget;
begin
     x1:=target[(l + r) div 2];
     i:=l;
     j:=r;
     repeat
           while target[i].x < x1.x do inc(i);
           while target[j].x > x1.x do dec(j);
           if i <= j then begin
              y1:=target[i]; target[i]:=target[j]; target[j]:=y1;
              inc(i);
              dec(j);
           end;
     until i > j;
     if i < r then sort(i,r);
     if l < j then sort(l,j);
end;

procedure sortn(l,r : longint);
var
   i,j : longint;
   x1,y1 : ttarget;
begin
     x1:=target[(l + r) div 2];
     i:=l;
     j:=r;
     repeat
           while target[i].num < x1.num do inc(i);
           while target[j].num > x1.num do dec(j);
           if i <= j then begin
              y1:=target[i]; target[i]:=target[j]; target[j]:=y1;
              inc(i);
              dec(j);
           end;
     until i > j;
     if i < r then sortn(i,r);
     if l < j then sortn(l,j);
end;

procedure bin(l,r : longint);
var
   m : longint;
begin
     if l > r then exit;
     m:=(l + r) div 2;
     if target[m].right >= x1 then begin
        if m < res then res:=m;
        bin(l,m-1);
     end else bin(m + 1,r);
end;

begin
     read(n);
     for i:=1 to n do begin
         read(x1,r);
         target[i].left:=x1 - r;
         target[i].right:=x1 + r;
         target[i].r:=r;
         target[i].x:=x1;
         target[i].status:=-1;
         target[i].num:=i;
     end;
     target[0].left:=-maxlongint;
     target[0].right:=-maxlongint;
     target[n+1].left:=-maxlongint;
     target[n+1].right:=-maxlongint;
     ans:=0;
     sort(1,n);
     read(m);
     for i:=1 to m do begin
         read(x1,y1);
         if (x1 < target[1].left) or (x1 > target[n].right) then continue;
         res:=n;
         bin(1,n-1);
         s:=sqrt(sqr(x1 - target[res].x) + sqr(y1));
         if s <= target[res].r then begin
            if target[res].status = -1 then begin
               target[res].status:=i;
               inc(ans);
            end;
         end;
         if (x1 = target[res + 1].left) and (y1 = 0) then begin
            if target[res + 1].status = -1 then begin
               target[res + 1].status:=i;
               inc(ans);
            end;
         end;
         //writeln(res,' ',s:1:4);
     end;
     writeln(ans);
     sortn(1,n);
     for i:=1 to n do write(target[i].status,' ');
end.