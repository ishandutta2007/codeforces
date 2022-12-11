program project1;

var
   minl,minr,maxl,maxr,a : array[1..100000] of longint;
   i,j,k,n,m : longint;

function min(a,b : longint):longint;
begin
     if a > b then min:=b else min:=a;
end;

function max(a,b : longint):longint;
begin
     if a > b then max:=a else max:=b;
end;

function is_sorted:boolean;
var
   i : longint;
   f1,f2 : boolean;
begin
     f1:=true;
     f2:=true;
     for i:=2 to n do if a[i] > a[i - 1] then f1:=false;
     for i:=2 to n do if a[i] < a[i - 1] then f2:=false;
     exit(f1 or f2);
end;

begin
     read(n);
     for i:=1 to n do read(a[i]);
     if is_sorted then begin
        writeln(0);
        halt(0);
     end;
     minl[1]:=0;
     minl[2]:=1;
     for i:=3 to n do begin
         minl[i]:=minl[i - 1];
         if a[i - 1] < a[minl[i]] then minl[i]:=i - 1;
     end;
     minr[n]:=0;
     minr[n - 1]:=n;
     for i:=n - 2 downto 1 do begin
         minr[i]:=minr[i + 1];
         if a[i + 1] < a[minr[i]] then minr[i]:=i + 1;
     end;
     maxl[1]:=0;
     maxl[2]:=1;
     for i:=3 to n do begin
         maxl[i]:=maxl[i - 1];
         if a[i - 1] > a[maxl[i]] then maxl[i]:=i - 1;
     end;
     maxr[n]:=0;
     maxr[n - 1]:=n;
     for i:=n - 2 downto 1 do begin
         maxr[i]:=maxr[i + 1];
         if a[i + 1] > a[maxr[i]] then maxr[i]:=i + 1;
     end;
     for i:=2 to n - 1 do begin
         if (a[i] > a[minl[i]]) and (a[i] > a[minr[i]]) then begin
            writeln('3');
            writeln(minl[i],' ',i,' ',minr[i]);
            halt(0);
         end;
         if (a[i] < a[maxl[i]]) and (a[i] < a[maxr[i]]) then begin
            writeln('3');
            writeln(maxl[i],' ',i,' ',maxr[i]);
            halt(0);
         end;
     end;
     for i:=1 to n do writeln(maxl[i],' ',maxr[i]);
end.