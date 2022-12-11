program project1;

var
   a : array[1..3] of longint;
   i,j : longint;

function max(a,b : longint):longint;
begin
     if a > b then max:=a else max:=b;
end;

begin
     for i:=1 to 3 do begin
         read(a[i]);
     end;
     i:=1;
     j:=0;
     while (a[1] <> 0) or (a[2] <> 0) or (a[3] <> 0) do begin
           a[i]:=max(0,a[i] - 2);
           inc(i);
           inc(j);
           if i = 4 then i:=1;
           //writeln(a[1],' ',a[2],' ',a[3]);
     end;
     writeln(j + 30 - 1);
end.