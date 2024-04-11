program CFP;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, y, i : integer;
  s, x : Int64;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  read(n, x, y);
  if n > y then writeln(-1)
  else
  begin
    s := y - (n-1);
    s := s * s;
    s := s + n-1;
    if s >= x then
    begin
      for i:=1 to n-1 do writeln(1);
      writeln(y-(n-1));
    end
    else
      Writeln(-1);
  end;
//  readln;readln;readln;
end.