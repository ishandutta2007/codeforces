program Project2;

{$APPTYPE CONSOLE}

var
  ost:array[0..2] of LongInt;
  i,j,k,n,ans:LongInt;
begin
  Readln(n);
  ans:=0;
  fillchar(ost,SizeOf(ost),0);
  for i:=1 to n do begin
    Read(k);
    j:=0;
    while k>0 do begin
      j:=j+(k mod 10);
      k:=k div 10;
      j:=j mod 3;
    end;
    Inc(ost[j]);
  end;
  ans:=ost[0] div 2;
  if ost[1]>ost[2] then ans:=ans+ost[2] else ans:=ans+ost[1];
  Writeln(ans);
end.