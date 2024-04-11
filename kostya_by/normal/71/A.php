<?php
class INPUT_HELP{
    public function read_array(){
        $a[0] = '';
        $j = 0;
        $input = fgets(STDIN);
        for ($i = 0; $i < strlen($input); $i++){
            if (preg_replace("/[0-9A-z-._-]/",null,$input[$i]) == false) {
                $a[$j] = $a[$j].$input[$i];
            } else {
                if ($a[$j] != '') {
                    ++$j;
                    $a[$j] = '';
                }
            }
        }
        return $a;
    }
    public function read_one(){
        $array = $this->read_array();
        return $array[0];
    }
}
?>
<?php
    $input_connect = new INPUT_HELP();
    $n = $input_connect->read_one();
    for ($i = 0; $i < $n; $i++){
        $st = $input_connect->read_one();
        if (strlen($st) > 10) {
            echo $st[0].(strlen($st) - 2).$st[strlen($st) - 1];
        } else echo $st;
        echo PHP_EOL;
    }
?>