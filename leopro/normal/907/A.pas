program A454;

var
  V1, V2, V3, Vm: LongInt;
  Car1, Car2: LongInt;
  min, max: LongInt;
  Possuble: Boolean;

procedure Change(var a, b: LongInt);
var
  tmp: LongInt;
begin
  tmp := b;
  b := a;
  a := tmp;
end;

begin
  Possuble:=True;
  Read(V1);    Read(V2); Read(V3); ReadLn(Vm);
  Car1 := V1 * 2;
  Car2 := V2 * 2;
  If Vm * 2 >= Car2 then Possuble := False;
  If Vm < V3 then Change(Vm, V3);
  min := Vm;
  max := V3 * 2;
  If min > max then Possuble:=False;
  If Possuble then
  begin
    WriteLn(Car1);
    WriteLn(Car2);
    WriteLn(max);
  end else
  begin
    WriteLn(-1);
   end; 
end.