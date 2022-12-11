program project1;

var
   a : array[1..100000] of longint;
   i,j,k,n,m,max1,max2 : longint;

procedure sort(l,r : longint);
var
   i,j,x,y : longint;
begin
     i:=l;
     j:=r;
     x:=a[(l + r) div 2];
     repeat
           while a[i] < x do inc(i);
           while a[j] > x do dec(j);
           if i <= j then begin
              y:=a[i]; a[i]:=a[j]; a[j]:=y;
              inc(i);
              dec(j);
           end;
     until i > j;
     if i < r then sort(i,r);
     if l < j then sort(l,j);
end;

begin
     read(n);
     max1:=1;
     for i:=1 to n do begin
         read(a[i]);
     end;
     sort(1,n);
     for i:=1 to n - 1 do begin
         if a[i] = a[i + 1] then continue;
         max1:=a[i + 1];
         max2:=a[i];
         max2:=max2 * 2;
         if (max1 < max2) then begin
                  writeln('YES');
                  halt(0);
         end;
     end;
     writeln('NO');
end.