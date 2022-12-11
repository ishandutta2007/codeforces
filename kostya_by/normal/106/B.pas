program project1;

var
   a,b,c,d : array[1..100] of longint;
   bool : array[1..100] of boolean;
   n,i,j : longint;
   min, num: longint;
begin
     read(n);
     min:=maxlongint;
     for i:=1 to n do read(a[i],b[i],c[i],d[i]);
     for i:=1 to n do begin
         for j:=1 to n do begin
             if (a[i] < a[j]) and (b[i] < b[j]) and (c[i] < c[j]) then begin
                bool[i]:=true;
             end;
         end;
     end;
     for i:=1 to n do begin
         if (bool[i] = false) and (d[i] < min) then begin
            min:=d[i];
            num:=i;
         end;
     end;
     writeln(num);
end.