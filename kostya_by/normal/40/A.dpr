program Project2;

{$APPTYPE CONSOLE}

var
  x,y,h:LongInt;
  d:Extended;
begin
  Readln(x,y);
  d:=Sqrt(Sqr(x)+sqr(y));
  h:=Trunc(Int(d));
  if Frac(d)=0 then Writeln('black') else
  begin
  if h mod 2=1 then
  begin
    if ((x<0)and(y<0)) or ((y>0)and(x>0)) then Writeln('white') else writeln('black');
  end;
  if h mod 2=0 then
  begin
    if ((x<0)and(y<0)) or ((y>0)and(x>0)) then Writeln('black') else writeln('white');
  end;
  end;
end.